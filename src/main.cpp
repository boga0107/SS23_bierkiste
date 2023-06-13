#include <Arduino.h>
hw_timer_t* timer = NULL;

void IRAM_ATTR onTimer()
{
  Serial.println("Milliseconds: "+ String(millis()));
}

void setup() {
  pinMode(18, OUTPUT);
  
  timer = timerBegin(0,80,true); //Timer_0, prescaling: 80MHz / 80 = 1MHz -> T=1 us
  timerAttachInterrupt(timer, onTimer, true); //Interrupt Funktion onTimer()
  timerAlarmWrite(timer, 1000000, true); //Faktor für Timer z.B. 1000000*1us = 1s
  // Faktor muss evtl halbiert werden. Aktueller Timer zählt 2 Sekunden lang 
  timerAlarmEnable(timer);
  Serial.begin(115200);
}


void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(18, HIGH);
  delay(1000);
  digitalWrite(18, LOW);
  delay(1000);

}
