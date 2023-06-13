#ifndef ANTRIEBSMOTOR_H
#define ANTRIEBSMOTOR_H

#include "pins.h"


class antrieb {
private:
    const uint8_t mThrottlePin;
    const uint8_t mDirectionPin;
    uint16_t mSpeed;
    boolean mDirection; 
        // TRUE = backwards
        // FALSE = forward
    
public:
    antrieb(uint8_t &pThrottlePin, uint8_t &pDirectionPin);
    boolean setDirection(boolean &pDirection); 
    boolean setSpeed(uint16_t &pSpeed);
    boolean setSaveState();

};

#endif