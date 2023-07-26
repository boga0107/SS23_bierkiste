#include <Arduino.h>
#include "uart_message.h"
#include "uart_message.cpp"

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

UartMessage myUart(rx_pin, tx_pin, 115200, SERIAL_8N1);
//UartMessage myUart2;
void setup() {
  
}

void loop() {
  myUart.buildMessage(myUart.getDirection(), myUart.getSpeed(), myUart.getDistance(0), myUart.getDistance(1), 
                      myUart.getDistance(2));
  //myUart.getMessage();
}


