#include <Arduino.h>
<<<<<<< HEAD
#include "uart_message.h"
=======
#include <iostream>
#include <string>

#include "uart.cpp"

>>>>>>> 9acd544b67f34b51fe6f55431846131e3b405ba1

// Pin Belegung
#define out_driveDirection  GPIO_NUM_5
#define out_driveThrottle   GPIO_NUM_18

#define sensor1_trigger     GPIO_NUM_23
#define sensor1_echo        GPIO_NUM_35
#define sensor2_trigger     GPIO_NUM_26
#define sensor2_echo        GPIO_NUM_27
#define sensor3_trigger     GPIO_NUM_12
#define sensor3_echo        GPIO_NUM_13
#define rx_pin              GPIO_NUM_16
#define tx_pin              GPIO_NUM_17

Uart myUart(rx_pin, tx_pin, 115200, SERIAL_8N1);

void setup() {
<<<<<<< HEAD
  
}

void loop() {
  myUart.buildMessage(myUart.getDirection(), myUart.getSpeed(), myUart.getDistance(0), myUart.getDistance(1), 
                      myUart.getDistance(2), myUart.getSteering(), myUart.getPower());
  myUart.getMessage();
=======
  Serial.begin(115200);
  // put your setup code here, to run once:
  Serial.println("Serial 9600 started");
  SerialPort.begin(115200, SERIAL_8N1, 16, 17); //using pin 16 and 17 on ESP (Baudrate, SerialMode, RX_pin, TX_pin)
  Serial.println("Serial 2 started");
}

void loop() {
  //Serial.println("start Loop");

  buildMessage(directionValue, speedValue, steeringValue, distance1Value, distance2Value, distance3Value);
  //Serial.print(msgUart);
  //getMessage((byte)msg); //string to byte conversion?? in what format is uart sent and received??
  // put your main code here, to run repeatedly:

  //SerialPort.write(msgUart); //uses uart_write_bytes()
   
  //Receive message
  if(SerialPort.available()){
    //Serial.println(SerialPort.available());
    
    uint8_t c[11];
    for (int i = 0; i<11; i++)
      c[i] = SerialPort.read(); //uses uart_read_bytes()
    //should be the byte that was send
    getMessage(c);  
    //char message = directionValue + ',' + speedValue + ',' + steeringValue + ',' + distance1Value
    //+ ',' + distance2Value + ',' + distance3Value;
    /*
    Serial.print(directionValue);
    Serial.print(", ");
    Serial.print(speedValue);
    Serial.print(", ");
    Serial.print(steeringValue);
    
    Serial.print(", ");
    Serial.print(distance1Value);
    Serial.print(", ");
    Serial.print(distance2Value);
    Serial.print(", ");
    Serial.println(distance3Value);
    */
    //Serial.println(directionValue);
    
  } else {
    //Serial.println("Error 404 NoMessageFound");
  }
>>>>>>> 9acd544b67f34b51fe6f55431846131e3b405ba1
}


