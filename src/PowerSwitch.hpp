//
// PowerSwitch.hpp
//

#ifndef __POWERSWITCH_HPP__
#define __POWERSWITCH_HPP__

#include "Lamp.hpp"
#include "TacticalSwitch.hpp"

class PowerSwitch : public TacticalSwitch
{
private:
    Lamp* lamp;

    bool isSwitchOn();
    void onSwitchOn();

public:
    PowerSwitch(Lamp* lamp) : TacticalSwitch(), lamp(lamp) {}
};

#endif

