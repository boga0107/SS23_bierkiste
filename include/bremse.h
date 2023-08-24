#ifndef BREMSE_H
#define BREMSE_H

#include <Arduino.h>
#include "pins.h"
#include "antriebsmotor.h"

#define BREAK_PWM_FREQUENCY 1000
#define BREAK_PWM_CHANNEL 0
#define BREAK_PWM_RESOLUTION 8
#define MIN_POSITION 2^8
#define MAX_POSITION 0
class Break{

private:
    
    boolean EmergencyBreakActive;

    antrieb &myAntrieb;

public:
    
    Break(antrieb &pAntrieb);

    void Activate_EmergencyBreak();
    void Deactivate_EmergencyBreak();
    boolean get_State_Break();

};


#endif