#include <Arduino.h>
#include "uart.cpp"
#include <iostream>
#include <string>


// Pin Belegung
#define out_driveDirection  GPIO_NUM_5
#define out_driveThrottle   GPIO_NUM_18

#define sensor1_trigger     GPIO_NUM_23
#define sensor1_echo        GPIO_NUM_35
#define sensor2_trigger     GPIO_NUM_26
#define sensor2_echo        GPIO_NUM_27
#define sensor3_trigger     GPIO_NUM_12
#define sensor3_echo        GPIO_NUM_13

//initialize UART Message
HardwareSerial SerialPort(2); //Use UART2

void setup() {
  // put your setup code here, to run once:
  SerialPort.begin(115200, SERIAL_8N1, 16, 17); //using pin 16 and 17 on ESP (Baudrate, SerialMode, RX_pin, TX_pin)
}

void loop() {

  buildMessage(directionValue, speedValue, steeringValue, distance1Value, distance2Value, distance3Value);
  //Serial.print(msgUart);
  //getMessage((byte)msg); //string to byte conversion?? in what format is uart sent and received??
  // put your main code here, to run repeatedly:

  SerialPort.write(msgUart); //uses uart_write_bytes()
   
  //Receive message
  if(SerialPort.available()>0){
    uint8_t c = SerialPort.read(); //uses uart_read_bytes()
    //should be the byte that was send
    getMessage(c);  
    char message = directionValue + ',' + speedValue + ',' + steeringValue + ',' + distance1Value
    + ',' + distance2Value + ',' + distance3Value;
    Serial.print(message);
  } else {
    Serial.print("Error 404 NoMessageFound");
  }
}

