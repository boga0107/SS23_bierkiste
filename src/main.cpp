#include <Arduino.h>
#include "uart_message.h"
#include "uart_message.cpp"
#include <AccelStepper.h>
#include "antriebsmotor.h"
#include "pins.h"
#include "sensors.h"
#include "sensors.cpp"
hw_timer_t *timer = NULL;

void IRAM_ATTR onTimer()
{
  Serial.println("Milliseconds: " + String(millis()));
}

AccelStepper stepper(AccelStepper::FULL4WIRE, 33, 32, 25, 14, true); // 4 wire full stepper
long steering_val = 0;

sensor mySensors(sensor1_trigger, sensor2_trigger, sensor3_trigger, sensor1_echo, sensor2_echo, sensor3_echo);
UartMessage myUart(rx_pin, tx_pin, 115200, SERIAL_8N1);

void setup() {
  timer = timerBegin(0, 80, true);            // Timer_0, prescaling: 80MHz / 80 = 1MHz -> T=1 us
  timerAttachInterrupt(timer, onTimer, true); // Interrupt Funktion onTimer()
  timerAlarmWrite(timer, 1000000, true);      // Faktor für Timer z.B. 1000000*1us = 1s
  // Faktor muss evtl halbiert werden. Aktueller Timer zählt 2 Sekunden lang
  timerAlarmEnable(timer);
  Serial.begin(115200);
  /*
  Hier evtl. IN- bzw. OUTPUTS deklarieren, sollte jedoch in der AccelStepper Library automatisch passieren
  */
  stepper.setAcceleration(5000); // Acceleration in steps/s^2
  stepper.setMaxSpeed(5000);     // Speed in steps/s
  stepper.setSpeed(2000);
  stepper.enableOutputs();
  // stepper.setOutputPins(AccelStepper::FULL4WIRE);
  stepper.setMinPulseWidth(20); // 20 microseconds
}

void loop() {
  // put your main code here, to run repeatedly:
  mySensors.readDistance();
  mySensors.distanceCheck();
  
  delay(1000); //pause für 1 s, determines the rate of distance calculation. Can be changed eventually (mimum 10)

  myUart.buildMessage(myUart.getDirection(), myUart.getSpeed(), myUart.getDistance(0), myUart.getDistance(1), myUart.getDistance(2));
   //myUart.getMessage();

   stepper.moveTo(steering_val * (-10)); // negative anticlockwise
  while (stepper.distanceToGo() != 0)
  {
    stepper.run();
  }
}

