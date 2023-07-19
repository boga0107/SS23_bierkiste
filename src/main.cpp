#include <Arduino.h>
#include <Ultrasonic.h>
#include "sensors.h"

// Pin Belegung
#define out_driveDirection  GPIO_NUM_5
#define out_driveThrottle   GPIO_NUM_18

#define sensor1_trigger     GPIO_NUM_23
#define sensor1_echo        GPIO_NUM_35
#define sensor2_trigger     GPIO_NUM_26
#define sensor2_echo        GPIO_NUM_27
#define sensor3_trigger     GPIO_NUM_12
#define sensor3_echo        GPIO_NUM_13

sensor sensors(sensor1_trigger, sensor2_trigger, sensor3_trigger, sensor1_echo, sensor2_echo, sensor3_echo);
void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensors.readDistance();
  sensors.distanceCheck();
  
  delay(1000); //pause für 1 s, determines the rate of distance calculation. Can be changed eventually (mimum 10)
}
