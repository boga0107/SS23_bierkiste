#include <Arduino.h>
#include <AccelStepper.h> 
#include <iostream>
#include <string> 

#include "uart.cpp"
#include "antriebsmotor.h"
#include "pins.h"

AccelStepper stepper(AccelStepper::FULL4WIRE,33,32,25,14,true);  // 4 wire full stepper
long steering_val=0;






void setup() {
  SerialPort.begin(15200, SERIAL_8N1, 16, 17); //using pin 16 and 17 on ESP (Baudrate, SerialMode, RX_pin, TX_pin)

  /*
  Hier evtl. IN- bzw. OUTPUTS deklarieren, sollte jedoch in der AccelStepper Library automatisch passieren
  */
  stepper.setAcceleration(5000);        // Acceleration in steps/s^2
  stepper.setMaxSpeed(5000);            // Speed in steps/s
  stepper.setSpeed(2000);
  stepper.enableOutputs();
  //stepper.setOutputPins(AccelStepper::FULL4WIRE);
  stepper.setMinPulseWidth(20);         // 20 microseconds

}

void loop() 
{
  buildMessage(directionValue, speedValue, steeringValue, distance1Value, distance2Value, distance3Value);
  Serial.print(msgUart);
  //getMessage((byte)msg); //string to byte conversion?? in what format is uart sent and received??
  // put your main code here, to run repeatedly:

  SerialPort.write(msgUart); //uses uart_write_bytes()
  
  //Receive message
  if(Serial.available()>0){
    uint8_t c = Serial.read(); //uses uart_read_bytes()
    //should be the byte that was send
    //how do we extract the bits out of the integer???
    getMessage(c);  
  }
  //if(uart.any())
  //{ 
      stepper.moveTo(steering_val*(-10)); // negative anticlockwise
      while(stepper.distanceToGo()!=0)
      {
        stepper.run();
      }
  //}
} 
