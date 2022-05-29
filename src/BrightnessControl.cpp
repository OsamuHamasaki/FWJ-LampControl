//
// BrightnessControl.cpp
//

#include "BrightnessControl.hpp"
#include "IO.hpp"

void BrightnessControl::notifyPowerSwitchPressed()
{
    switch (state)
    {
        case OFF:
            IO_lampBrighten();
            state = BRIGHT;
            break;
        default:
            state = OFF;
            break;
    }
}

void BrightnessControl::notifyBrightnessSwitchPressed()
{
    switch (state)
    {
        case BRIGHT:
            IO_lampDarken();
            state = DARK;
            break;
        case DARK:
            IO_lampBrighten();
            state = BRIGHT;
            break;
    }
}

