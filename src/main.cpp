#include <Arduino.h>

#define RXD2 16
#define TXD2 17

byte direction = 0;
uint16_t speed = 0;
int16_t steering = 0;


void setup() {
  Serial.begin(115200);
  Serial.println("Test");
  Serial2.begin(115200, SERIAL_8N1, RXD2, TXD2);
  
}


void loop() {
  if(Serial2.available()>=5){
    Serial.print(Serial2.available());
    Serial.print(" - ");

    byte* steering_ptr = (byte*)&steering;
    for(int i = 0; i < sizeof(steering); i++)
    {
      steering_ptr[i] = Serial.read();
    }
    Serial.print(steering);
    Serial.print(" ");
    
    byte* speed_ptr = (byte*)&speed;
    for (int i = 0; i < sizeof(speed); i++)
    {
      speed_ptr[i] = Serial.read();
    }
    Serial.print(speed);
    Serial.print(" ");

    direction = Serial2.read();
    Serial.print(direction);
  
    
    Serial.println();
   
  }  

}

