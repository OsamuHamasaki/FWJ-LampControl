//
// BlinkControl.hpp
//

#ifndef __BLINKCONTROL_HPP__
#define __BLINKCONTROL_HPP__

class BlinkControl 
{
private:
    static const int stateOff = 0;
    static const int stateOn = 1;
    static const int stateBlinkOn = 2;
    static const int stateBlinkOff = 3;

    static const int initialCount = 10;

    int state;
    int count;

public:
    BlinkControl() : state(stateOff), count(0) {}

    void notifyPowerSwitchPressed();
    void notifyBlinkSwitchPressed();

    void tick();
};

#endif
