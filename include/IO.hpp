//
// IO.hpp
//

#ifndef __IO_HPP__
#define __IO_HPP__

bool IO_initialize();
void IO_finalize();
bool IO_isPowerSwitchOn();
bool IO_isBrightnessSwitchOn();
bool IO_isBlinkSwitchOn();
void IO_lampOn();
void IO_lampOff();
void IO_lampBrighten();
void IO_lampDarken();
void IO_tick();

#endif

