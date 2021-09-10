//
// BrightnessControl.cpp
//

#include "BrightnessControl.hpp"
#include "IO.hpp"

void BrightnessControl::start()
{
    state = stateBright;
}

void BrightnessControl::notifyBrightnessSwitchPressed()
{
    if (state == stateBright)
    {
        state = stateDark;
        IO_lampDarken();
    }
    else
    {
        state = stateBright;
        IO_lampBrighten();
    }
}

