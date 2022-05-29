//
// BlinkSwitch.hpp
//

#ifndef __BLINKSWITCH_HPP__
#define __BLINKSWITCH_HPP__

#include "Switch.hpp"
#include "IO.hpp"
#include "Lamp.hpp"

class BlinkSwitch : public Switch
{
private:
    Lamp* lamp;

    virtual bool isSwitchOn() { return IO_isBlinkSwitchOn(); }
    virtual void onSwitchPressed() { lamp->notifyBlinkSwitchPressed(); }

public:
    BlinkSwitch(Lamp* lamp) : lamp(lamp) {}
    virtual ~BlinkSwitch() {}

};

#endif

