//
// LampConctrol main program
//

#include <iostream>
#include <unistd.h>
#include <cstring>
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
        usleep(100000);
    }

    finalize();

    return 0;
}

