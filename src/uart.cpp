#include <HardwareSerial.h>
#include <Arduino.h>
#include <fstream>
#include <iostream>
#include <string.h>

char msg[]={};
String msgUart;

String buildMessage(uint8_t uart, int direction, int speed, int steering_val, int distance1, int distance2, int distance3)
{
    msg[0]= direction;
    msg[1] = speed;
    msg[2] = steering_val;
    msg[3] = distance1;
    msg[4] = distance2;
    msg[5] = distance3;
   
   for(int i = 0; i < 8; i++){
        msgUart += msg[i];
   }
    Serial.print(msgUart);
    return msgUart;
}
void getMessage (uint8_t uart){
    
}