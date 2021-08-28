//
// BrightnessControl.cpp
//

#include "BrightnessControl.hpp"
#include "IO.hpp"

void BrightnessControl::notifyPowerSwitchPressed()
{
    if (state == stateOff)
    {
        state = stateBright;
        IO_lampBrighten();
    }
    else
    {
        state = stateOff;
    }
}

void BrightnessControl::notifyBrightnessSwitchPressed()
{
    if (state == stateBright)
    {
        state = stateDark;
        IO_lampDarken();
    }
    else if (state == stateDark)
    {
        state = stateBright;
        IO_lampBrighten();
    }
}

