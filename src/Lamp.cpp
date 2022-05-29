//
// Lamp.cpp
//

#include "Lamp.hpp"
#include "IO.hpp"
#include "BrightnessControl.hpp"

void Lamp::notifyPowerSwitchPressed()
{
    brightnessControl.notifyPowerSwitchPressed();
    blinkControl.notifyPowerSwitchPressed();
}

void Lamp::notifyBrightnessSwitchPressed()
{
    brightnessControl.notifyBrightnessSwitchPressed();
}

void Lamp::notifyBlinkSwitchPressed()
{
    blinkControl.notifyBlinkSwitchPressed();
}

void Lamp::tick()
{
    blinkControl.tick();
}

