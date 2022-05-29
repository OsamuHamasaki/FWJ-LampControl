//
// Lamp.hpp
//

#ifndef __LAMP_HPP__
#define __LAMP_HPP__

#include "BrightnessControl.hpp"
#include "BlinkControl.hpp"

class Lamp
{
private:
    BrightnessControl brightnessControl;
    BlinkControl blinkControl;

public:
    Lamp() : brightnessControl(), blinkControl() {}
    ~Lamp() {}

    void notifyPowerSwitchPressed();
    void notifyBrightnessSwitchPressed();
    void notifyBlinkSwitchPressed();

    void tick();
};

#endif

