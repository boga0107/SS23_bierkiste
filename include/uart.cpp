#include <HardwareSerial.h>
#include <Arduino.h>
#include <fstream>
#include <iostream>
#include <string.h>
#include <cstddef>
#include <cstring>

char msg[]={};
char* msgUart;

int directionValue = 1;
int speedValue = 0;
int steeringValue = 1;
int distance1Value = 0;
int distance2Value = 0;
int distance3Value = 1;


void buildMessage(int direction, int speed, int steering_val, int distance1, int distance2, int distance3)
{
    msg[0] = direction;
    msg[1] = speed;
    msg[2] = steering_val;
    msg[3] = distance1;
    msg[4] = distance2;
    msg[5] = distance3;
   
   for(int i = 0; i < 8; i++){
        msgUart += msg[i];
   }
}

void getMessage (uint8_t uart){
    uint8_t *uartAdress;
    uartAdress = &uart;

    // shift to read individual bits in a byte
    // value = a & (1 << i);
    directionValue = uart & (1 << 0); //should read the 1st bit of the uart byte
    speedValue = uart & (1 << 1);
    steeringValue = uart & (1 << 2);
    distance1Value = uart & (1 << 3);
    distance2Value = uart & (1 << 4);
    distance3Value = uart & (1 << 5);
    // to think about: muss uart statt uint8_t als byte übergeben werden?
    
    
    //convert uint8_t value into separate values??
    // directionValue = uart[0];
    // speedValue = uart[1];
    // steeringValue = uart[2];
    //...
}