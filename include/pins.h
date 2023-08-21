#ifndef PINS_H
#define PINS_H

#include "Arduino.h"

// Pin Belegung
#define out_driveDirection  0
#define out_driveThrottle   4
#define out_brake           27

#define sensor1_trigger     23
#define sensor1_echo        22
#define sensor2_trigger     19
#define sensor2_echo        18
#define sensor3_trigger     5
#define sensor3_echo        21
#define rx_pin              16
#define tx_pin              17
#define N_STEERING_DIRECTION 32
#define P_STEERING_DIRECTION 33
#define N_STEERING_PULSE    25
#define P_STEERING_PULSE    26

#endif