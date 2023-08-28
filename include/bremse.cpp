#include "bremse.h"

Break::Break(antrieb &pAntrieb): myAntrieb(pAntrieb), EmergencyBreakActive(false)
{
    ledcSetup(BREAK_PWM_CHANNEL, BREAK_PWM_FREQUENCY, BREAK_PWM_RESOLUTION);
    ledcAttachPin(out_brake,BREAK_PWM_CHANNEL);
}

/*Function to engage the break
maxDutyCycle was checked manually
*/
void Break::Activate_EmergencyBreak()
{
    ledcWrite(BREAK_PWM_CHANNEL, BREAK_SET);
    myAntrieb.setSaveState();
    EmergencyBreakActive = true;
}

/*Function to deactivate/ go to starting position*/
void Break::Deactivate_EmergencyBreak()
{
    ledcWrite(BREAK_PWM_CHANNEL, BREAK_LOOSE);
    EmergencyBreakActive = false;
}

/*Function to get to know the sate of the break.
If Break is engaged then 1, if not then 0.*/
 boolean Break::get_State_Break()
 {
    return EmergencyBreakActive;
 }