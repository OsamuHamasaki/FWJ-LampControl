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
    static const int stateBlink = 2;

    int tickCountForBlinkCycle;

    int state;
    int count;

public:
    BlinkControl(int tickCountForBlinkCycle) : tickCountForBlinkCycle(tickCountForBlinkCycle), state(stateOff), count(0) {}

    void notifyPowerSwitchPressed();
    void notifyBlinkSwitchPressed();

    void tick();
};

#endif

