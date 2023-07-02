#include <HardwareSerial.h>
#include <Arduino.h>
#include <fstream>
#include <iostream>
#include <string.h>
#include <cstddef>
#include <cstring>

char msg[]={};
char* msgUart;

uint8_t directionValue = 1;
int speedValue = 0;
int steeringValue = 1;
int distance1Value = 0;
int distance2Value = 0;
int distance3Value = 1;


void buildMessage(int direction, int speed, int steering_val, int distance1, int distance2, int distance3)
{
    //Serial.println("start buildmessage");
    msg[0] = direction;
    msg[1] = speed;
    msg[2] = steering_val;
    msg[3] = distance1;
    msg[4] = distance2;
    msg[5] = distance3;
   
   for(int i = 0; i < 8; i++){
        msgUart += msg[i];
   }

   //Serial.println("end buildmessage");
}

void getMessage (uint8_t uart[11]){
    //Serial.println("start getmessage");
    for (int i = 0; i<11; i++){
        Serial.print(uart[i], HEX);
        Serial.print(" ");
    }
    Serial.print("\n");


    //Serial.println(uart);

    
    
    //Serial.println("end getmesssage");
    
    //convert uint8_t value into separate values??
    // directionValue = uart[0];
    // speedValue = uart[1];
    // steeringValue = uart[2];
    //...
}