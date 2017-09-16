#include <xc.h>
#include "pulse_E.h"
#include "config.h"
#include <stdbool.h>


void lcdInit(void)
{
    /* 4 bit LCD interface initialisation
     * connection between uController and LCD
     RA4 --> D7
     RA2 --> D6
     RA1 --> D5
     RA0 --> D4
     RC1 --> E
     RC0 --> RS*/
    __delay_ms(100);        // power on, wait for power to settle - step 1
    /*************************************************************/
    RS = 0;                 // RS   RW  D7  D6  D5  D4 - step 2
    PORTAbits.RA4 = 0;      //  0   0   0   0   1   1  in hex 0x03 Function Set
    PORTAbits.RA2 = 0;      // interface is 8 bit still (default on power up))
    PORTAbits.RA1 = 1;
    PORTAbits.RA0 = 1;
    __delay_ms(5);          // long delay needed at first Function Set 8 bit
    pulse_E();              // pulse enable pin of LCD to latch data in
    /*************************************************************/
    /*************************************************************/
    RS = 0;                 // RS   RW  D7  D6  D5  D4 - step 3
    PORTAbits.RA4 = 0;      //  0   0   0   0   1   1 in hex 0x03 Function Set 8 bit
    PORTAbits.RA2 = 0;      // interface is 8 bit still (default on power up)
    PORTAbits.RA1 = 1;
    PORTAbits.RA0 = 1;
    __delay_us(120);
    pulse_E();
    /*************************************************************/
    /*************************************************************/
    RS = 0;                 // RS   RW  D7  D6  D5  D4 - step 4
    PORTAbits.RA4 = 0;      //  0   0   0   0   1   1   in hex 0x03 Function Set 8 bit
    PORTAbits.RA2 = 0;      // interface is 8 bit still (default on power up)
    PORTAbits.RA1 = 1;
    PORTAbits.RA0 = 1;
    __delay_us(200);
    pulse_E();
    /*************************************************************/
    /*************************************************************/
    RS = 0;                 // RS   RW  D7  D6  D5  D4 - step 5
    PORTAbits.RA4 = 0;      //  0   0   0   0   1   0 in hex 0x20 Function Set 4 bit interface
    PORTAbits.RA2 = 0;
    PORTAbits.RA1 = 1;      
    PORTAbits.RA0 = 0;  // DL = display interface length if DL = 1  8bit or DL = 0 4bit display interface
    __delay_us(200);
    pulse_E();
    /*************************************************************/
    /*************************************************************/
    RS = 0;                 // RS   RW  D7  D6  D5  D4 - step 6a
    PORTAbits.RA4 = 0;      //  0   0   0   0   1   0  in hex 0x20 Function Set 4 bit
    PORTAbits.RA2 = 0;       // interface is now 4 bit
    PORTAbits.RA1 = 1;      
    PORTAbits.RA0 = 0;  // DL = display interface length if DL = 1  8bit or DL = 0 4bit display interface
    __delay_us(200);
    pulse_E();
    /*************************************************************/
    /*************************************************************/
    RS = 0;                 // RS   RW  D7  D6  D5  D4 - step 6b
    PORTAbits.RA4 = 1;      //  0   0   1   1   0   0  // Specify number of display lines N (2 lines))
    PORTAbits.RA2 = 1;                                 // and character font F (5 x 10 dots)
    PORTAbits.RA1 = 0;      // don't care
    PORTAbits.RA0 = 0;      // don't care
    __delay_us(200);
    pulse_E();
    /*************************************************************/
    /*************************************************************/
    RS = 0;                 // RS   RW  D7  D6  D5  D4 - step 7a
    PORTAbits.RA4 = 0;      //  0   0   0   0   0   0
    PORTAbits.RA2 = 0;
    PORTAbits.RA1 = 0;
    PORTAbits.RA0 = 0;
    __delay_us(200);
    pulse_E();
    /*************************************************************/
    /*************************************************************/
    RS = 0;                 // RS   RW  D7  D6  D5  D4 - step 7b
    PORTAbits.RA4 = 1;      //  0   0   1   0   0   0 N = 1, so 2 line display
    PORTAbits.RA2 = 1;      // Font F = 1 so font is 5 x 10 dots
    PORTAbits.RA1 = 0;  // don't care
    PORTAbits.RA0 = 0;  // don't care
    __delay_us(200);
    pulse_E();
    /*************************************************************/
    /*************************************************************/
    RS = 0;                 // RS   RW  D7  D6  D5  D4 - step 8a - clear display
    PORTAbits.RA4 = 0;      //  0   0   0   0   0   0
    PORTAbits.RA2 = 0;
    PORTAbits.RA1 = 0;
    PORTAbits.RA0 = 0;
    __delay_us(200);
    pulse_E();
    /*************************************************************/
    /*************************************************************/
    RS = 0;                 // RS   RW  D7  D6  D5  D4 - step 8b - clear display
    PORTAbits.RA4 = 0;      //  0   0   0   0   0   1
    PORTAbits.RA2 = 0;
    PORTAbits.RA1 = 0;
    PORTAbits.RA0 = 1;
    __delay_us(200);
    pulse_E();
    /*************************************************************/
    /*************************************************************/
    RS = 0;                 // RS   RW  D7  D6  D5  D4 - step 9a
    PORTAbits.RA4 = 0;      //  0   0   0   0   0   0
    PORTAbits.RA2 = 0;
    PORTAbits.RA1 = 0;
    PORTAbits.RA0 = 0;
   __delay_ms(5);
    pulse_E();
    /*************************************************************/
    /*************************************************************/
    RS = 0;                 // RS   RW  D7  D6  D5  D4 - step 9b
    PORTAbits.RA4 = 0;      //  0   0   0   1   1   0
    PORTAbits.RA2 = 1;      // entry mode set bit
    PORTAbits.RA1 = 1;      // I/D increment/ decrement I/D = 1 cursor moves right, I/D = 0 cursor moves left
    PORTAbits.RA0 = 0;      // shift display S = 1 enables shift, S = 0 disables shift
    __delay_ms(5);
    pulse_E();
    /*************************************************************/
    
    /*************************************************************/
    RS = 0;                 // RS   RW  D7  D6  D5  D4 - step 10a Display on/off control
    PORTAbits.RA4 = 0;      //  0   0   0   0   0   0
    PORTAbits.RA2 = 0;
    PORTAbits.RA1 = 0;
    PORTAbits.RA0 = 0;
   __delay_ms(5);
    pulse_E();
    /*************************************************************/
    /*************************************************************/
    RS = 0;                 // RS   RW  D7  D6  D5  D4 - step 10b
    PORTAbits.RA4 = 1;      //  0   0   1   1   1   1
    PORTAbits.RA2 = 1;      // D =1 display ON
    PORTAbits.RA1 = 1;      // C =1 cursor ON
    PORTAbits.RA0 = 1;      // B = 1 blinking ON
    __delay_ms(5);
    pulse_E();
    /*************************************************************/
    
}
