//
// BrightnessControl.hpp
//

#ifndef __BRIGHTNESSCONTROL_HPP__
#define __BRIGHTNESSCONTROL_HPP__

class BrightnessControl 
{
private:
    static const int stateBright = 1;
    static const int stateDark = 2;

    int state;

public:
    BrightnessControl() : state(stateBright) {}

    void start();
    void notifyBrightnessSwitchPressed();
};

#endif

