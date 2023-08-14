#ifndef PINS_H
#define PINS_H

#include "Arduino.h"

// Pin Belegung
#define out_driveDirection  GPIO_NUM_5
#define out_driveThrottle   GPIO_NUM_18
#define out_brake           GPIO_NUM_27

#define sensor1_trigger     GPIO_NUM_23
#define sensor1_echo        GPIO_NUM_35
#define sensor2_trigger     GPIO_NUM_36
#define sensor2_echo        GPIO_NUM_27
#define sensor3_trigger     GPIO_NUM_12
#define sensor3_echo        GPIO_NUM_13
#define rx_pin              GPIO_NUM_16
#define tx_pin              GPIO_NUM_17


#endif