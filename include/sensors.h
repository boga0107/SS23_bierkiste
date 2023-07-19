#include <Arduino.h>
#include <Ultrasonic.h>

//class to define the HC-SR04 Sensors
//contains:
// read distance
// ghost avoidance --- to implement
// security definitions of emergency break
//check if distance is either below emergency break distance or above maximal distance measued.

class sensor {

private:
    const uint8_t emergencyDistanceValue = 70;
    const uint8_t maximalDistanceValue = 350;
    const uint8_t sensorTriggerPin1;
    const uint8_t sensorTriggerPin2;
    const uint8_t sensorTriggerPin3;
    const uint8_t sensorEchoPin1;
    const uint8_t sensorEchoPin2;
    const uint8_t sensorEchoPin3;
    uint8_t distance1;
    uint8_t distance2;
    uint8_t distance3;

public:
    sensor(uint8_t &pTriggerPin1, uint8_t &pTriggerPin2, uint8_t &pTriggerPin3, uint8_t &pEchoPin1
    , uint8_t &pEchoPin2, uint8_t &pEchoPin3);

    void readDistance();
    void setDistance(uint8_t value, uint8_t number);
    uint8_t getDistance1();
    void distanceCheck();
    bool securityCheck(uint8_t sensorNumber);
};