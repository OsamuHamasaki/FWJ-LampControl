//
// BlinkSwitch.cpp
//

#include "BlinkSwitch.hpp"
#include "IO.hpp"
#include "Lamp.hpp"

bool BlinkSwitch::isSwitchOn()
{
    return IO_isBlinkSwitchOn();
}

void BlinkSwitch::onSwitchOn()
{
    lamp->notifyBlinkSwitchPressed();
}

