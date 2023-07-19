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
    const uint16_t emergencyDistanceValue = 70;
    const uint16_t maximalDistanceValue = 350;
    const uint8_t sensorTriggerPin1;
    const uint8_t sensorTriggerPin2;
    const uint8_t sensorTriggerPin3;
    const uint8_t sensorEchoPin1;
    const uint8_t sensorEchoPin2;
    const uint8_t sensorEchoPin3;
    uint16_t distance1;
    uint16_t distance2;
    uint16_t distance3;

public:
    sensor(uint8_t TriggerPin1, uint8_t TriggerPin2, uint8_t TriggerPin3, uint8_t EchoPin1
    , uint8_t EchoPin2, uint8_t EchoPin3);

    void readDistance();
    void setDistance(uint16_t value, uint8_t number);
    uint16_t getDistance(uint8_t number);
    void distanceCheck();
    bool securityCheck(uint8_t sensorNumber);
};