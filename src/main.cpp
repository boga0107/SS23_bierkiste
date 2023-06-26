#include <Arduino.h>
hw_timer_t* timer = NULL;

bool flag1ms = false;
bool stateLED = 0;
uint32_t counter1ms = 0;

// PWM variables
const int LEDPin = 14;
int dutyCycle;

const int PWMFreq = 5000;
const int PWMChannel = 0;
const int PWMResolution = 12;
const int MAX_DUTY_CYCLE = (int)(pow(2, PWMResolution)-1);

void IRAM_ATTR onTimer()
{
  //Serial.println("Milliseconds: "+ String(millis()));
  counter1ms++;
  if(counter1ms%1000==0){
    stateLED = !stateLED;
    digitalWrite(18, stateLED);
  }
  flag1ms=true;

}



void setup() {
  pinMode(18, OUTPUT);

  Serial.begin(115200);
  
  timer = timerBegin(0,80,true); //Timer_0, prescaling: 80MHz / 80 = 1MHz -> T=1 us
  timerAttachInterrupt(timer, onTimer, true); //Interrupt Funktion onTimer()
  timerAlarmWrite(timer, 1000, true); //Faktor für Timer z.B. 1000000*1us = 1s
  // Faktor muss evtl halbiert werden. Aktueller Timer zählt 2 Sekunden lang 
  timerAlarmEnable(timer);
  //Serial.begin(115200);

  // PWM Setup
  ledcSetup(PWMChannel, PWMFreq, PWMResolution);
  ledcAttachPin(LEDPin, PWMChannel);

  // Doku zu ESP32 PWM - https://tinyurl.com/afapekcf

}


void loop() {
  if(flag1ms){
    dutyCycle++;
    dutyCycle %= MAX_DUTY_CYCLE;
    ledcWrite(PWMChannel, dutyCycle);
    flag1ms = false;
  }
  Serial.println("Test");

}

