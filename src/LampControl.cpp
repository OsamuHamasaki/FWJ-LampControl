//
// LampConctrol main program
//

#include <iostream>
#include <unistd.h>
#include <cstring>
#include "IO.hpp"
#include "LampController.hpp"

static int tickInterval_us = 10000;
static LampController controller;

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
    controller.tick();
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
        usleep(tickInterval_us);
    }

    finalize();

    return 0;
}

