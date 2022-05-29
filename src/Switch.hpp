//
// Switch.hpp
//

#ifndef __SWITCH_HPP__
#define __SWITCH_HPP__

class Switch
{
private:
    bool isOnPrev;

    virtual bool isSwitchOn() = 0;
    virtual void onSwitchPressed() = 0;

public:
    Switch() : isOnPrev(false) {}
    virtual ~Switch() {}

    void tick();
};

#endif

