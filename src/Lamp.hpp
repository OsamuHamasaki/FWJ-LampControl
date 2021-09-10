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
    class State
    {
    protected:
        Lamp* lamp;

    public:
        State(Lamp* lamp) : lamp(lamp) {}
        virtual ~State() {}

        virtual void notifyPowerSwitchPressed() {};
        virtual void notifyBrightnessSwitchPressed() {};
        virtual void notifyBlinkSwitchPressed() {};
        virtual void tick() {};
    };

    class OffState : public State
    {
    public:
        OffState(Lamp* lamp) : State(lamp) {}
        ~OffState() {}

        void notifyPowerSwitchPressed();
    };

    class OnState : public State
    {
    public:   
        OnState(Lamp* lamp) : State(lamp) {}
        ~OnState() {}

        void notifyPowerSwitchPressed();
        void notifyBrightnessSwitchPressed();
        void notifyBlinkSwitchPressed();
        void tick();
    };

    OffState stateOff;
    OnState stateOn;

    BrightnessControl brightnessControl;
    BlinkControl blinkControl;
    State* state;

public:
    Lamp(int tickCountForBlinkCycle)
        : stateOff(this), stateOn(this), brightnessControl(), blinkControl(tickCountForBlinkCycle), state(&stateOff) {}

    void notifyPowerSwitchPressed();
    void notifyBrightnessSwitchPressed();
    void notifyBlinkSwitchPressed();
    void tick();
};

#endif

