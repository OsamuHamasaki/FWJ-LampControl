//
// BlinkControl.cpp
//

#include "BlinkControl.hpp"
#include "IO.hpp"

void BlinkControl::StateOn::notifyBlinkSwitchPressed()
{
    control->count = control->tickCountForBlinkCycle;
    control->state = &(control->stateBlink);
}

void BlinkControl::StateBlink::notifyBlinkSwitchPressed()
{
    IO_lampOn();
    control->state = &(control->stateOn);
}

void BlinkControl::StateBlink::tick()
{
    control->count--;
    if (control->count == control->tickCountForBlinkCycle / 2)
    {
        IO_lampOff();
    }
    else if (control->count == 0)
    {
        IO_lampOn();
        control->count = control->tickCountForBlinkCycle;
    }
}

void BlinkControl::start()
{
    state = &stateOn;
}

void BlinkControl::notifyBlinkSwitchPressed()
{
    state->notifyBlinkSwitchPressed();
}

void BlinkControl::tick()
{
    state->tick();
}

