#include <xc.h>
#include "config.h"
#include "transmit_character.h"
void transmit_character(void)
{
    TXREG = at_codes[0];        // put 'A' into TXREG to start a transmission
}
