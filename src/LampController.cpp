//
// LampController.cpp
//

#include "LampController.hpp"
#include "Lamp.hpp"
#include "PowerSwitch.hpp"
#include "BrightnessSwitch.hpp"

void LampController::tick()
{
    lamp.tick();

    powerSwitch.tick();
    brightnessSwitch.tick();
    blinkSwitch.tick();
}

