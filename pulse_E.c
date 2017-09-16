#include <xc.h>
#include "config.h"
#include <stdbool.h>

void pulse_E(void)
{
    E = 1;          //#define E PORTCbits.RC1     E enable write pin 15
    __delay_ms(1);
    E = 0;
}

