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
  if(Serial2.read()==0xAA){
    Serial.print(Serial2.available());
    Serial.print(" - ");

   direction = Serial2.read();
    Serial.print(direction);
    Serial.print(" ");

    byte* speed_ptr = (byte*)&speed;
    speed_ptr[0] = Serial2.read();
    speed_ptr[1] = Serial2.read();
    Serial.print(speed);
    Serial.print(" ");

    byte* steering_ptr = (byte*)&steering;
    steering_ptr[0] = Serial2.read();
    steering_ptr[1] = Serial2.read();
    Serial.print(steering);

    
    Serial.println();
   
  }  

}

