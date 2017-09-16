#include <xc.h>
#include "config.h"
#include <stdbool.h>
#include "main.h"
#include "pulse_E.h"
#include <stdio.h>
#include "init_ports.h"
#include "init_eusart.h"
#include "lcdInit.h"
#include "lcdData.h"
#include "splash_screen.h"
#include "putch.h"





#include "get_at_code.h"
#include "transmit_character.h"

uchar main (void)
{
    uchar j;
    uchar sw = 0x00;
    init_ports();
    init_eusart();
    lcdInit();
    lcdData(0x82, 0);   //position cursor at position 2 of first line
    splash_screen();
    lcdData(0xc0, 0);   //position cursor at start of second line
      
    while(1)    
    { 
       get_at_code();      
       lcdData(0xc7,0);         // move cursor to 2nd line, position 7
       for (j = 0; j < 8; j++)
        {
            lcdData(at_codes[j], 1);// echo keyboard input to LCD
            putch(at_codes[j]);
        }
       while(1);
    }     
}
