//
// TacticalSwitch.cpp
//

#include "TacticalSwitch.hpp"

void TacticalSwitch::tick()
{
    bool isOnNow = isSwitchOn();

    if (!isOnPrev && isOnNow)
    {
        onSwitchOn();
    }

    isOnPrev = isOnNow;
}

