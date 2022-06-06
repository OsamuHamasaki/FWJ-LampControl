//
// BlinkControl.cpp
//

#include "BlinkControl.hpp"
#include "IO.hpp"

void BlinkControl::notifyPowerSwitchPressed()
{
    switch (state)
    {
        case OFF:
            IO_lampOn();
            state = ON;
            break;
        default: 
            IO_lampOff();
            state = OFF;
            break;
    }
}

void BlinkControl::notifyBlinkSwitchPressed()
{
    switch (state)
    {
        case ON:
            count = BLINK_CYCLE_10MS;
            state = BLINK;
            break;
        case BLINK:
            IO_lampOn();
            state = ON;
            break;
    }
}

void BlinkControl::tick()
{
    if (state != BLINK || count == 0)
    {
        return;
    }
    
    count = count - 1;
    if (count == BLINK_CYCLE_10MS / 2)
    {
        IO_lampOff();
    }
    else if (count == 0)
    {
        IO_lampOn();
        count = BLINK_CYCLE_10MS;
    }
}

