//
// PowerSwitch.hpp
//

#ifndef __POWERSWITCH_HPP__
#define __POWERSWITCH_HPP__

#include "Switch.hpp"
#include "IO.hpp"
#include "Lamp.hpp"

class PowerSwitch : public Switch
{
private:
    Lamp* lamp;

    virtual bool isSwitchOn() { return IO_isPowerSwitchOn(); }
    virtual void onSwitchPressed() { lamp->notifyPowerSwitchPressed(); }

public:
    PowerSwitch(Lamp* lamp) : lamp(lamp) {}
    virtual ~PowerSwitch() {}

};

#endif

