#ifndef SENSORS_H
#define SENSORS_H
#include <Arduino.h>
#include <Ultrasonic.h>
#include "bremse.h"

/* class to define the HC-SR04 Sensors
 * contains:
 * read distance
 * ghost avoidance --- to implement
 * security definitions of emergency break
 * check if distance is either below emergency break distance or above maximal distance measued.
 * */

#define EMERGENCY_DISTANCE_VALUE 100
#define MAXIMAL_DISTANCE_VALUE 350

class sensor
{

private:
    const uint8_t sensorTriggerPin1;
    const uint8_t sensorTriggerPin2;
    const uint8_t sensorTriggerPin3;
    const uint8_t sensorEchoPin1;
    const uint8_t sensorEchoPin2;
    const uint8_t sensorEchoPin3;
    uint16_t distance1;
    uint16_t distance2;
    uint16_t distance3;

    Ultrasonic sensor1;
    Ultrasonic sensor2;
    Ultrasonic sensor3;

    Break &myBreak;

public:
    sensor(uint8_t TriggerPin1, uint8_t TriggerPin2, uint8_t TriggerPin3,
           uint8_t EchoPin1, uint8_t EchoPin2, uint8_t EchoPin3, Break &pBreak);

    void readDistance();
    void setDistance(uint16_t pDistance, uint8_t sensorIndex);
    uint16_t getDistance(uint8_t sensorIndex);
    bool distanceOK();
    bool securityCheck(uint8_t sensorIndex);
};
#endif