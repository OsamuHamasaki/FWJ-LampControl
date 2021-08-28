//
// BlinkSwitch.hpp
//

#ifndef __BLINKSWITCH_HPP__
#define __BLINKSWITCH_HPP__

#include "Lamp.hpp"
#include "TacticalSwitch.hpp"

class BlinkSwitch : public TacticalSwitch
{
private:
    Lamp* lamp;

    bool isSwitchOn();
    void onSwitchOn();

public:
    BlinkSwitch(Lamp* lamp) : TacticalSwitch(), lamp(lamp) {}
};

#endif

