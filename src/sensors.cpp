#include <Ultrasonic.h>

//class to define the HC-SR04 Sensors
//contains:
// read distance
// ghost avoidance --- to implement
// security definitions of emergency break

// int safetyCheck = 0; //Check which sensor got a signal
int emergencyBreakValue = 70; //Distance to trigger emergency break. Now set to default = 70 cm.
int maximalDistanceValue = 350; 
int sensors[3];

//check if distance is either below emergency break distance or above maximal distance measued.
void distanceCheckEasy(int emergencyBreak, int maxDistance, int sensorValue)
{
  if(sensorValue < emergencyBreak){
    Serial.println("error ");
  }
  if(sensorValue > maxDistance){
    Serial.println("too far away ");
  }
}

// check if distance is below emergency break distance. 
// emergency distance is kept as parameter to be more accessible during programming than a fixed value

// bool distanceCheck(int emergencyBreak, int sensorNumber)
// {
//   switch(sensorNumber)
//   {
//     case 0:
//       if (sensors[0] > emergencyBreak){
//         //safetyCheck++;
//         return true;
//       }
//     case 1:
//       if (sensors[1] > emergencyBreak){
//         //safetyCheck++;
//         return true;
//       }
//     case 2:
//       if (sensors[2] > emergencyBreak){
//         //safetyCheck++;
//         return true;
//       }
//     default:
//       return false;
//   }
// }

// to check if sensors are correct (triplet-system based)
// to be implemented in further steps
bool securityCheck(int sensorNumber){

}
