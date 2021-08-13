//
// LampConctrol main program
//

#include <iostream>
#include <unistd.h>
#include "IO.hpp"

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
        usleep(10000);
    }

    finalize();

    return 0;
}

