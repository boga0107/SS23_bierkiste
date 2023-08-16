#ifndef BREMSE_H
#define BREMSE_H

#include <Arduino.h>
#include "pins.h"
#include "antriebsmotor.h"

#define BREAK_PWM_FREQUENCY 5000
#define BREAK_PWM_CHANNEL 1
#define BREAK_PWM_RESOLUTION 8
class Break{

private:
    
    boolean EmergencyBreakActive;

    uint8_t DutyCycle;
    uint8_t maxDutyCycle;

    antrieb &myAntrieb;

public:
    
    Break(antrieb &pAntrieb);

    void Activate_EmergencyBreak();
    void Deactivate_EmergencyBreak();
    boolean get_State_Break();

};


#endif