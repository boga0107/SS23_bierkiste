#include <Arduino.h>
#include <Ultrasonic.h>
#include <sensors.cpp>

// Pin Belegung
#define out_driveDirection  GPIO_NUM_5
#define out_driveThrottle   GPIO_NUM_18

#define sensor1_trigger     GPIO_NUM_23
#define sensor1_echo        GPIO_NUM_35
#define sensor2_trigger     GPIO_NUM_26
#define sensor2_echo        GPIO_NUM_27
#define sensor3_trigger     GPIO_NUM_12
#define sensor3_echo        GPIO_NUM_13


Ultrasonic sensor1(sensor1_trigger, sensor1_echo);
Ultrasonic sensor2(sensor2_trigger, sensor2_echo);
Ultrasonic sensor3(sensor3_trigger, sensor3_echo);


void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  // sensors[0] = sensor1.read(); //Reads distance in cm
  // sensors[1] = sensor2.read();
  // sensors[2] = sensor3.read();

  distanceCheckEasy(emergencyBreakValue, maximalDistanceValue, sensor1.read());
  distanceCheckEasy(emergencyBreakValue, maximalDistanceValue, sensor2.read());
  distanceCheckEasy(emergencyBreakValue, maximalDistanceValue, sensor3.read());

  delay(1000); //pause für 1 s, determines the rate of distance calculation. Can be changed eventually (mimum 10)
}

  // for(int i = 0; i<3; i++){
  //   if(distanceCheck(emergencyBreakValue, i) == false){
  //     //before interrupting check value again to avoid ghosts
  //     //interrupt, emergency break!
  //     //to implement: motor stop (up to date emergency stop)
  //     printf("EMERGENCY BREAK");
  //   } //else continue;
  // }