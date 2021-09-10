//
// Lamp.cpp
//

#include "Lamp.hpp"
#include "BrightnessControl.hpp"
#include "BlinkControl.hpp"
#include "IO.hpp"

void Lamp::OffState::notifyPowerSwitchPressed()
{
    IO_lampBrighten();
    IO_lampOn();

    lamp->brightnessControl.start();
    lamp->blinkControl.start();

    lamp->state = &(lamp->stateOn);
}

void Lamp::OnState::notifyPowerSwitchPressed()
{
    IO_lampOff();

    lamp->state = &(lamp->stateOff);
}

void Lamp::OnState::notifyBrightnessSwitchPressed()
{
    lamp->brightnessControl.notifyBrightnessSwitchPressed();
}

void Lamp::OnState::notifyBlinkSwitchPressed()
{
    lamp->blinkControl.notifyBlinkSwitchPressed();
}

void Lamp::OnState::tick()
{
    lamp->blinkControl.tick();
}

void Lamp::notifyPowerSwitchPressed()
{
    state->notifyPowerSwitchPressed();
}

void Lamp::notifyBrightnessSwitchPressed()
{
    state->notifyBrightnessSwitchPressed();
}

void Lamp::notifyBlinkSwitchPressed()
{
    state->notifyBlinkSwitchPressed();
}

void Lamp::tick()
{
    state->tick();
}

