#include <Arduino.h>

#define RXD2 16
#define TXD2 17

byte serialRXBuffer[5];
byte serialTXBuffer[7];
byte direction = 0;
uint16_t speed = 0;
int16_t steering = 0;
uint16_t distances[3];

void setup()
{
  Serial.begin(115200);
  Serial.println("Test");
  Serial2.begin(115200, SERIAL_8N1, RXD2, TXD2);
}

void loop()
{
  distances[0] = 50;
  distances[1] = 150;
  distances[2] = 200;
  if (Serial2.read() == 0xAA)
  {
    // read message
    Serial.print(Serial2.available());
    Serial.print(" - ");
    Serial2.readBytes(serialRXBuffer, 5);

    // Zuordnen der empfangenen Daten
    direction = serialRXBuffer[0];
    Serial.print(direction);
    Serial.print(" ");

    byte *speed_ptr = (byte *)&speed;
    speed_ptr[0] = serialRXBuffer[1];
    speed_ptr[1] = serialRXBuffer[2];
    Serial.print(speed);
    Serial.print(" ");

    byte *steering_ptr = (byte *)&steering;
    steering_ptr[0] = serialRXBuffer[3];
    steering_ptr[1] = serialRXBuffer[4];
    Serial.print(steering);

    Serial.println();
  } 
  /*
  serialTXBuffer[0] = 0xAA;
  byte *distance_ptr = (byte *)&distances;
  for (int i = 0; i < 6; i++)
  {
    serialTXBuffer[i + 1] = distance_ptr[i];
  }
  delayMicroseconds(1000);
  Serial2.write(serialTXBuffer, 7);
  */
}
