//
// BrightnessSwitch.hpp
//

#ifndef __BRIGHTNESSSWITCH_HPP__
#define __BRIGHTNESSSWITCH_HPP__

#include "Switch.hpp"
#include "IO.hpp"
#include "Lamp.hpp"

class BrightnessSwitch : public Switch
{
private:
    Lamp* lamp;

    virtual bool isSwitchOn() { return IO_isBrightnessSwitchOn(); }
    virtual void onSwitchPressed() { lamp->notifyBrightnessSwitchPressed(); }

public:
    BrightnessSwitch(Lamp* lamp) : lamp(lamp) {}
    virtual ~BrightnessSwitch() {}

};

#endif

