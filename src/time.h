#ifndef TIME_H
#define TIME_H

#include "asm_io.h"

void sleep(unsigned int microseconds)
{
    int i;
    for(i=0; i<microseconds; i++)
    {
        inb(0x80);
    }
}
#endif
