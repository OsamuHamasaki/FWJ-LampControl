//
// BrightnessControl.hpp
//

#ifndef __BRIGHTNESSCONTROL_HPP__
#define __BRIGHTNESSCONTROL_HPP__

class BrightnessControl
{
private:
    static const int OFF = 0;
    static const int BRIGHT = 1;
    static const int DARK = 2;

    int state;

public:
    BrightnessControl() : state(OFF) {}
    ~BrightnessControl() {}

    void notifyPowerSwitchPressed();
    void notifyBrightnessSwitchPressed();
};

#endif

