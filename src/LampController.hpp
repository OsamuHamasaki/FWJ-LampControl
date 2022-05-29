//
// LampController.hpp
//

#ifndef __LAMPCONTROLLER_HPP__
#define __LAMPCONTROLLER_HPP__

#include "Lamp.hpp"
#include "PowerSwitch.hpp"
#include "BrightnessSwitch.hpp"
#include "BlinkSwitch.hpp"

class LampController
{
private:
    Lamp lamp;

    PowerSwitch powerSwitch;
    BrightnessSwitch brightnessSwitch;
    BlinkSwitch blinkSwitch;

public:
    LampController() : lamp(), powerSwitch(&lamp), brightnessSwitch(&lamp), blinkSwitch(&lamp) {}
    ~LampController() {}

    void tick();
};

#endif

