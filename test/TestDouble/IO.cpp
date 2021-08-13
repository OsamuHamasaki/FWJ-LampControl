//
// IO.cpp (for Unit test)
//

#include "IO.hpp"
#include "IOforTest.hpp"

bool isPowerSwitchOn;
bool isBrightnessSwitchOn;
bool isBlinkSwitchOn;
bool isLampOn;
bool isLampBright;

bool IO_initialize()
{
    isPowerSwitchOn = false;
    isBrightnessSwitchOn = false;
    isBlinkSwitchOn = false;

    isLampOn = true;
    isLampBright = false;

    return true;
}

void IO_finalize()
{
    // do nothing
}

bool IO_isPowerSwitchOn()
{
    return isPowerSwitchOn;
}

bool IO_isBrightnessSwitchOn()
{
    return isBrightnessSwitchOn;
}

bool IO_isBlinkSwitchOn()
{
    return isBlinkSwitchOn;
}

void IO_lampOn()
{
    isLampOn = true;
}

void IO_lampOff()
{
    isLampOn = false;
}

void IO_lampBrighten()
{
    isLampBright = true;
}

void IO_lampDarken()
{
    isLampBright = false;
}

void IO_tick()
{
    // do nothing
}

// for Test only

void IO_powerSwitchOn()
{
    isPowerSwitchOn = true;
}

void IO_powerSwitchOff()
{
    isPowerSwitchOn = false;
}

void IO_brightnessSwitchOn()
{
    isBrightnessSwitchOn = true;
}

void IO_brightnessSwitchOff()
{
    isBrightnessSwitchOn = false;
}

void IO_blinkSwitchOn()
{
    isBlinkSwitchOn = true;
}

void IO_blinkSwitchOff()
{
    isBlinkSwitchOn = false;
}

bool IO_isLampOn()
{
    return isLampOn;
}

bool IO_siLampBright()
{
    return isLampBright;
}

