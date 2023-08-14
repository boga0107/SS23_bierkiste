#include "bremse.h"

Break::Break(antrieb &pAntrieb):PWM_Freq(5000), PWM_Channel(0), PWM_Resolution(8), myAntrieb(pAntrieb)
{
    DutyCycle = 0;
    maxDutyCycle = 100;
    ledcSetup(PWM_Channel, PWM_Freq, PWM_Resolution);
    ledcAttachPin(out_brake,PWM_Channel);
}

void Break::Activate_EmergencyBreak()
{
    ledcWrite(PWM_Channel, maxDutyCycle);
    myAntrieb.setSaveState();
}

void Break::Deactivate_EmergencyBreak()
{
    myAntrieb.setSaveState();
    ledcWrite(PWM_Channel, DutyCycle);
}