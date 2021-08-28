//
// TacticalSwitch.hpp
//

#ifndef __TACTICALSWITCH_HPP__
#define __TACTICALSWITCH_HPP__

class TacticalSwitch
{
private:
    bool isOnPrev;

    virtual bool isSwitchOn() = 0; 
    virtual void onSwitchOn() = 0;

public:
    TacticalSwitch() : isOnPrev(false) {}
    virtual ~TacticalSwitch() {}

    void tick();
};

#endif

