//
// BlinkControl.hpp
//

#ifndef __BLINKCONTROL_HPP__
#define __BLINKCONTROL_HPP__

class BlinkControl 
{
private:
    class State
    {
    protected:
        BlinkControl* control;
    public:
        State(BlinkControl* control) : control(control) {}
        virtual ~State() {}

        virtual void notifyBlinkSwitchPressed() {}
        virtual void tick() {}
    };

    class StateOn : public State
    {
    public:
        StateOn(BlinkControl* control) : State(control) {}
        ~StateOn() {}

        void notifyBlinkSwitchPressed();
    };

    class StateBlink : public State
    {
    public:
        StateBlink(BlinkControl* control) : State(control) {}
        ~StateBlink() {}

        void notifyBlinkSwitchPressed();
        virtual void tick();
    };

    StateOn stateOn;
    StateBlink stateBlink;

    int tickCountForBlinkCycle;

    State* state;
    int count;

public:
    BlinkControl(int tickCountForBlinkCycle) 
        : stateOn(this), stateBlink(this), tickCountForBlinkCycle(tickCountForBlinkCycle), state(&stateOn), count(0) {}

    void start();
    void notifyBlinkSwitchPressed();
    void tick();
};

#endif

