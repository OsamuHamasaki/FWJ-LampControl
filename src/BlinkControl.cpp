//
// BlinkControl.cpp
//

#include "BlinkControl.hpp"
#include "IO.hpp"

void BlinkControl::notifyPowerSwitchPressed()
{
    if (state == stateOff)
    {
        state = stateOn;
        IO_lampOn();
    }
    else
    {
        count = 0;
        state = stateOff;
        IO_lampOff();
    }
}

void BlinkControl::notifyBlinkSwitchPressed()
{
    if (state == stateOn)
    {
        state = stateBlinkOn;
        count = initialCount;
    }
    else if (state != stateOff)
    {
        count = 0;
        state = stateOn;
        IO_lampOn();
    }
}

void BlinkControl::tick()
{
    if (count == 0) return;

    count--;
    if (count == 0)
    {
        if (state == stateBlinkOn)
        {
            state = stateBlinkOff;
            IO_lampOff();
        }
        else
        {
            state = stateBlinkOn;
            IO_lampOn();
        }

        count = initialCount;
    }
}

