#include <Arduino.h>

#define RXD2 16
#define TXD2 17


void setup() {
  Serial.begin(115200);
  Serial.println("Test");
  Serial2.begin(115200, SERIAL_8N1, RXD2, TXD2);
  
}


void loop() {
  if(Serial2.available()){
    Serial.print(Serial2.available());
    Serial.print(" - ");
    for (int i = 0; i < 9; i++)
    {
      Serial.print(Serial2.read());
      Serial.print(" ");
    }
    Serial.println();
  }  

}

