#include "sensors.h"

sensor::sensor(uint8_t TriggerPin1, uint8_t TriggerPin2,
               uint8_t TriggerPin3, uint8_t EchoPin1,
               uint8_t EchoPin2, uint8_t EchoPin3, Break &pBreak) : sensorTriggerPin1(TriggerPin1), sensorTriggerPin2(TriggerPin2),
                                                                    sensorTriggerPin3(TriggerPin3), sensorEchoPin1(EchoPin1),
                                                                    sensorEchoPin2(EchoPin2), sensorEchoPin3(EchoPin3), myBreak(pBreak),
                                                                    sensor1(sensorTriggerPin1, sensorEchoPin1),
                                                                    sensor2(sensorTriggerPin2, sensorEchoPin2),
                                                                    sensor3(sensorTriggerPin3, sensorEchoPin3),
                                                                    mIndex(0)
{
  pinMode(sensor1_trigger, OUTPUT);
  pinMode(sensor1_echo, INPUT);
  pinMode(sensor2_trigger, OUTPUT);
  pinMode(sensor2_echo, INPUT);
  pinMode(sensor3_trigger, OUTPUT);
  pinMode(sensor3_echo, INPUT);

  for (uint8_t i = 0; i < FILTER_SIZE; i++)
  {
    distance1Filter[i] = sensor1.read();
    distance2Filter[i] = sensor2.read();
    distance3Filter[i] = sensor3.read();
  }
}

void sensor::setDistance(uint16_t pDistance, uint8_t sensorIndex)
{
  if (pDistance == 0)
  {
    Serial.print("Sensor ");
    Serial.print(sensorIndex);
    Serial.println(" not working!");
  }
  switch (sensorIndex)
  {
  case 1:
    distance1Filter[mIndex] = pDistance;
    distance1 = 0;
    for (uint8_t i = 0; i < FILTER_SIZE; i++)
    {
      distance1 += distance1Filter[i];
    }
    distance1 = distance1 / FILTER_SIZE;

    Serial.print("Sensor 1: ");
    Serial.println(distance1);

    break;
  case 2:
    distance2Filter[mIndex] = pDistance;
    distance2 = 0;
    for (uint8_t i = 0; i < FILTER_SIZE; i++)
    {
      distance2 += distance2Filter[i];
    }
    distance2 = distance2 / FILTER_SIZE;

    Serial.print("Sensor 2: ");
    Serial.println(distance2);

    break;
  case 3:
    distance3Filter[mIndex] = pDistance;
    distance3 = 0;
    for (uint8_t i = 0; i < FILTER_SIZE; i++)
    {
      distance3 += distance3Filter[i];
    }
    distance3 = distance3 / FILTER_SIZE;

    Serial.print("Sensor 3: ");
    Serial.println(distance3);

    break;
  default:
    // do nothing for now
    break;
  }
}

/* read the distance and break if necessary*/
void sensor::readDistance()
{
  setDistance(sensor1.read(), 1);
  setDistance(sensor2.read(), 2);
  setDistance(sensor3.read(), 3);
  mIndex++;
  mIndex %= FILTER_SIZE;

  if (!distanceOK())
    myBreak.Activate_EmergencyBreak();
}

uint16_t sensor::getDistance(uint8_t sensorIndex)
{
  switch (sensorIndex)
  {
  case 1:
    return distance1;
  case 2:
    return distance2;
  case 3:
    return distance3;
  default:
    return 0; /* might cause an emergency break */
  }
}

// check if distance is below emergency break distance.
bool sensor::distanceOK()
{
  bool distanceState = true;
  for (int i = 1; i < 4; i++)
  {
    if (getDistance(i) < EMERGENCY_DISTANCE_VALUE)
    {
      distanceState &= false;
    }
  }
  return distanceState;
}

// to check if sensors are correct (triplet-system based)
// to be implemented in further steps
bool sensor::securityCheck(uint8_t sensorIndex)
{
  return true;
}
