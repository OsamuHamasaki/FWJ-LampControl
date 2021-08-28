//
// LampConctrol main program
//

#include <iostream>
#include <unistd.h>
#include <cstring>
#include "IO.hpp"
#include "Lamp.hpp"
#include "PowerSwitch.hpp"
#include "BrightnessSwitch.hpp"
#include "BlinkSwitch.hpp"

Lamp lamp;
PowerSwitch powerSwitch(&lamp);
BrightnessSwitch brightnessSwitch(&lamp);
BlinkSwitch blinkSwitch(&lamp);

bool initialize()
{
    return IO_initialize();
}

void finalize()
{
    IO_finalize();
}

void tick()
{
    IO_tick();
    powerSwitch.tick();
    brightnessSwitch.tick();
    blinkSwitch.tick();
    lamp.tick();
}

int main()
{
    if (!initialize()) 
    {
        std::cout << "Error socket:" << std::strerror(errno);
        exit(1);
    }
    
    for ( ; ;)
    {
        tick();
        usleep(50000);
    }

    finalize();

    return 0;
}

