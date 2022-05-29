//
// BlinkControl.hpp
//

#ifndef __BLINKCONTROL_HPP__
#define __BLINKCONTROL_HPP__

class BlinkControl
{
private:
    static const int OFF = 0;
    static const int ON = 1;
    static const int BLINK = 2;

    static const int BLINK_CYCLE_10MS = 100;

    int state;
    int count;

public:
    BlinkControl() : state(OFF), count(0) {}
    ~BlinkControl() {}

    void notifyPowerSwitchPressed();
    void notifyBlinkSwitchPressed();

    void tick();
};

#endif

