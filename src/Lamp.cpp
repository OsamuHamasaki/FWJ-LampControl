//
// Lamp.cpp
//

#include "Lamp.hpp"
#include "BrightnessControl.hpp"
#include "BlinkControl.hpp"

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

