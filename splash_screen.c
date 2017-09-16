#include <xc.h>
#include "pulse_E.h"
#include "config.h"
#include <stdbool.h>
#include "lcdData.h"

void splash_screen(void)
{
    uchar element;
    const uchar splash[13] = {0x45, 0x6e, 0x74, 0x65, 0x72, 0x20, 0x41, 0x54, 0x20, 0x63, 0x6f, 0x64, 0x65};// Enter AT code
    for (element = 0; element < 13; element++)
    {
        lcdData(splash[element], 1);
    }  
   
}
