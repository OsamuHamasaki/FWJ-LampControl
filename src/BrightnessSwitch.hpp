//
// BrightnessSwitch.hpp
//

#ifndef __BRIGHTNESSSWITCH_HPP__
#define __BRIGHTNESSSWITCH_HPP__

#include "Lamp.hpp"
#include "TacticalSwitch.hpp"

class BrightnessSwitch : public TacticalSwitch
{
private:
    Lamp* lamp;

    bool isSwitchOn();
    void onSwitchOn();

public:
    BrightnessSwitch(Lamp* lamp) : TacticalSwitch(), lamp(lamp) {}
};

#endif

