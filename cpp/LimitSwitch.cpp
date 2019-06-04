#include "LimitSwitch.h"

LimitSwitch::LimitSwitch(int channel, bool normallyOpen) 
{
    limitSwitch = new DigitalInput(channel);
    isNormallyOpen = normallyOpen;
}

bool LimitSwitch::isPressed() 
{
    bool limitPressed = limitSwitch->Get();

    if(isNormallyOpen == true)
    {
        limitPressed = limitPressed^true;
    }

    return limitPressed;
}
