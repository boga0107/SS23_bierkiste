/*
 * Project: Autonome Bierkiste SS23
 * At the MMT faculty, students collaboratively developed a beer crate with an electric drive.
 * Following that, the code for the autonomous driving function of the beer crate was implemented.
 * In this process, C++ proved to be the ideal programming language for this task.
 *
 * Created by: Gabriel Boehm, Isabel Kraus, Walter Orlov, Dennis Schell
 *
 */

/* All necessary classes */
#include <Arduino.h>
#include "uart_message.h"
#include "uart_message.cpp"
#include <AccelStepper.h>
#include "antriebsmotor.h"
#include "antriebsmotor.cpp"
#include "pins.h"
#include "sensors.h"
#include "sensors.cpp"
#include "bremse.h"
#include "bremse.cpp"
#include <esp_task_wdt.h> /* Load Watchdog-Library */

/* defines */
#define WDT_TIMEOUT_SECONDS 10
/* global variables */
/* timer variables */
hw_timer_t *timer = NULL;
uint32_t counter1ms = 0;
bool flagSensor = false;

int16_t steering_val = 0;
byte direction = 0;
uint16_t speed = 270;

/* global objets */
AccelStepper stepper(AccelStepper::FULL4WIRE,
                     P_STEERING_PULSE,
                     N_STEERING_PULSE,
                     P_STEERING_DIRECTION,
                     N_STEERING_DIRECTION,
                     true); // 4 wire full stepper
UartMessage myUart(rx_pin, tx_pin, 115200, SERIAL_8N1);
antrieb myAntrieb(out_driveThrottle, out_driveDirection);
Break myBreak(myAntrieb);
sensor mySensors(sensor1_trigger, sensor2_trigger, sensor3_trigger, sensor1_echo, sensor2_echo, sensor3_echo, myBreak);

/* Function prototypes */
void setup();
void loop();
void timer_init();
void stepper_init();
void IRAM_ATTR onTimer();
void ISR_Emergancy_Break();

/* Setup function
 * initialisation of timer, stepper and watchdog
 */
void setup()
{
  timer_init();
  stepper_init();
  speed = 90;
  myAntrieb.setSpeed(speed);

  /* Watchdog Setup */
  esp_task_wdt_init(WDT_TIMEOUT_SECONDS, true); /* Init Watchdog with 5 seconds timeout and panicmode */
  esp_task_wdt_add(NULL);                       /* No special task executed before restart */
  Serial.begin(115200);
  Serial.println("Setup done");
  myBreak.Deactivate_EmergencyBreak();

  attachInterrupt(digitalPinToInterrupt(INTERRUPT_BREAK), ISR_Emergancy_Break, FALLING);
}

/* Loop function
 * endless loop, controls the autonomous driving
 */
void loop()
{
  /* execute the distance reading every 20ms */
  if (flagSensor)
  {
    // Serial.print(counter1ms);
    // Serial.println(" - measure");
    mySensors.readDistance();
    flagSensor = false;

    if (!mySensors.distanceOK())
      myBreak.Activate_EmergencyBreak();
  }

  /* check for messages in the UART */
  if (myUart.msgAvailable())
  {
    // Serial.println("Uart received");
    /* read the instructions from the surface */
    myUart.getInstructions();
    if (mySensors.distanceOK())
    {
      if (myBreak.get_State_Break())
      {
        myBreak.Deactivate_EmergencyBreak();
      }

      /* set direction  */
      myUart.getDirection(direction);
      myAntrieb.setDirection(direction);

      /* set the steering */
      myUart.getSteering(steering_val);
      steering_val = 0.7 * steering_val;
      stepper.moveTo(steering_val * (-10)); // negative anticlockwise
      /*
      while (stepper.distanceToGo() != 0)
      {
        stepper.run();
      }
      */

      /* set the speed */
      myUart.getSpeed(speed);
      myAntrieb.setSpeed(speed);
    }
    else
    {
      // Serial.println("Distance not ok");
    }
  }

  if (stepper.distanceToGo() != 0)
  {
    stepper.run();
  }

  esp_task_wdt_reset(); // reset watchdog timer
}

/* Timer initialisation */
void timer_init()
{
  timer = timerBegin(0, 80, true);            /* Timer_0, prescaling: 80MHz / 80 = 1MHz -> T=1 us */
  timerAttachInterrupt(timer, onTimer, true); /* Interrupt Funktion onTimer() */
  timerAlarmWrite(timer, 1000, true);         /* Faktor für Timer z.B. 1000000*1us = 1s */
  timerAlarmEnable(timer);
}

/* Initialisation of stepper */
void stepper_init()
{

  stepper.setAcceleration(5000); /* Acceleration in steps/s^2 */
  stepper.setMaxSpeed(5000);     /* Speed in steps/s */
  stepper.setSpeed(2000);
  stepper.enableOutputs();
  stepper.setMinPulseWidth(20); /* 20 microseconds */
}

/* Timer interrupt service routine */
void IRAM_ATTR onTimer()
{
  counter1ms++;
  // Serial.println(counter1ms);
  if (counter1ms % 100 == 0)
  {
    // Serial.println(counter1ms);
    flagSensor = true;
  }
}

/* ISR Emergancy Break */
void IRAM_ATTR ISR_Emergancy_Break()
{
  myAntrieb.setSaveState();
}