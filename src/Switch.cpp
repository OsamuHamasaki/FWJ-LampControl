//
// Switch.cpp
//

#include "Switch.hpp"

void Switch::tick()
{
    bool isOnNow = isSwitchOn();

    if (!isOnPrev && isOnNow)
    {
        onSwitchPressed();
    }

    isOnPrev = isOnNow;
}

