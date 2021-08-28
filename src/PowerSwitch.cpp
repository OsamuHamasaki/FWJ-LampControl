//
// PowerSwitch.cpp
//

#include "PowerSwitch.hpp"
#include "IO.hpp"
#include "Lamp.hpp"

bool PowerSwitch::isSwitchOn()
{
    return IO_isPowerSwitchOn();
}

void PowerSwitch::onSwitchOn()
{
    lamp->notifyPowerSwitchPressed();
}

