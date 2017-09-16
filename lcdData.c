#include <xc.h>
#include "pulse_E.h"
#include "config.h"
#include <stdbool.h>
void lcdData (uchar data, bool inst_dat)
{
    uchar hi_nib, lo_nib;
   
    RS = inst_dat;         
    __delay_ms(1);
    hi_nib = (data & 0xf0) >> 4;    // throw away everything except bits 7 - 4 and then move all four bits to the low nibble
    lo_nib = data & 0x0f;           // throw away everything except bits 3 - 0
    
    PORTAbits.RA0 = hi_nib & 0x01; // copy lo_nib bit_0 to PORTAbits.RA0
    PORTAbits.RA1 = (hi_nib & 0x02)/2; // copy lo_nib bit_1 to PORTAbits.RA1
    PORTAbits.RA2 = (hi_nib & 0x04)/4; // copy lo_nib bit_2 to PORTAbits.RA2
    PORTAbits.RA4 = (hi_nib & 0x08)/8; // copy lo_nib bit_3 to PORTAbits.RA4
     __delay_ms(5);
    pulse_E();
   
    
    PORTAbits.RA0 = lo_nib & 0x01; // copy lo_nib bit_0 to PORTAbits.RA0
    PORTAbits.RA1 = (lo_nib & 0x02)/2; // copy lo_nib bit_1 to PORTAbits.RA1
    PORTAbits.RA2 = (lo_nib & 0x04)/4; // copy lo_nib bit_2 to PORTAbits.RA2
    PORTAbits.RA4 = (lo_nib &0x08)/8; // copy lo_nib bit_3 to PORTAbits.RA4
    __delay_ms(5);
    pulse_E();
}
