#include <xc.h>
#include "config.h"
uchar getch (void)
{
    while (!RCIF)   // halt the program while the receive interrupt flag is set
    {
        continue;
    }
    return RCREG;   // return 8 bit value captured to the caller
}

