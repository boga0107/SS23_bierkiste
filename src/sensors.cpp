#include <Arduino.h>

//class to define the HC-SR04 Sensors
//contains:
// read distance
// ghost avoidance --- to implement
// security definitions of emergency break
//check if distance is either below emergency break distance or above maximal distance measued.

int emergencyDistanceValue = 70; //fixed value
int maximalDistanceValue = 350; //fixed value

// check if distance is below emergency break distance. 
void distanceCheck(int sensorValue)
{
  if(sensorValue < emergencyDistanceValue){
    Serial.println("error ");
  }
  if(sensorValue > maximalDistanceValue){
    Serial.println("too far away ");
  }
}

// to check if sensors are correct (triplet-system based)
// to be implemented in further steps
bool securityCheck(int sensorNumber){

}

