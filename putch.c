#include <xc.h>
#include "config.h"
void putch (uchar alpha)
{
    while(!TXIF)     // halt the program while the transmit interrupt flag is set
        {
            continue;
        }
        TXREG = alpha;  // load the 8 bit value in alpha into TXREG register to start transmision
}
