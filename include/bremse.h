#ifndef BREMSE_H
#define BREMSE_H

#include <Arduino.h>
#include "pins.h"
#include "antriebsmotor.h"

class Break{

private:
    const uint16_t PWM_Freq;
    const uint8_t PWM_Channel;
    const uint8_t PWM_Resolution;
    uint8_t DutyCycle;
    uint8_t maxDutyCycle;

    antrieb &myAntrieb;

public:
    
    Break(antrieb &pAntrieb);

    void Activate_EmergencyBreak();
    void Deactivate_EmergencyBreak();

};


#endif