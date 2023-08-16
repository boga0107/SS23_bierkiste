#include "bremse.h"

Break::Break(antrieb &pAntrieb):PWM_Freq(5000), PWM_Channel(0), PWM_Resolution(8), myAntrieb(pAntrieb), EmergencyBreakActive(0)
{
    DutyCycle = 0;
    maxDutyCycle = 100;
    ledcSetup(PWM_Channel, PWM_Freq, PWM_Resolution);
    ledcAttachPin(out_brake,PWM_Channel);
}

/*Function to engage the break
maxDutyCycle was checked manually
*/
void Break::Activate_EmergencyBreak()
{
    ledcWrite(PWM_Channel, maxDutyCycle);
    myAntrieb.setSaveState();
    EmergencyBreakActive = 1;
}

/*Function to deactivate/ go to starting position*/
void Break::Deactivate_EmergencyBreak()
{
    ledcWrite(PWM_Channel, DutyCycle);
    EmergencyBreakActive = 0;
}

/*Function to get to know the sate of the break.
If Break is engaged then 1, if not then 0.*/
 boolean Break::get_State_Break()
 {
    return EmergencyBreakActive;
 }