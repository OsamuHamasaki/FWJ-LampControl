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
        state = stateOff;
        IO_lampOff();
    }
}

void BlinkControl::notifyBlinkSwitchPressed()
{
    if (state == stateOn)
    {
        state = stateBlink;
        count = tickCountForBlinkCycle;
    }
    else if (state != stateOff)
    {
        state = stateOn;
        IO_lampOn();
    }
}

void BlinkControl::tick()
{
    if (state != stateBlink) return;

    count--;
    if (count == tickCountForBlinkCycle / 2)
    {
        IO_lampOff();
    }
    else if (count == 0)
    {
        IO_lampOn();
        count = tickCountForBlinkCycle;
    }
}

