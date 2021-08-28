//
// BrightnessSwitch.cpp
//

#include "BrightnessSwitch.hpp"
#include "IO.hpp"
#include "Lamp.hpp"

bool BrightnessSwitch::isSwitchOn()
{
    return IO_isBrightnessSwitchOn();
}

void BrightnessSwitch::onSwitchOn()
{
    lamp->notifyBrightnessSwitchPressed();
}

