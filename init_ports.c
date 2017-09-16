#include <xc.h>
void init_ports(void)
{
    ANSEL = 0x00;           // ADC off
    ANSELH = 0x00;
    CM1CON0 = 0x00;         // comparators off
    CM2CON0 = 0x00;
    /* AT code switch inputs to 16f690 microcontroller*/
    TRISCbits.TRISC2 = 1;   // UP input pin 14 ATphabet input selection 
    TRISCbits.TRISC3 = 1;   // DOWN input pin 7 ATphabet input selection 
    TRISCbits.TRISC4 = 1;   // ENTER button pin 6
    /* LCD interface with 16f690 microcontroller*/
    TRISCbits.TRISC0 = 0;   // output pin 16
    TRISCbits.TRISC1 = 0;   // output pin 15
    TRISAbits.TRISA0 = 0;   // output pin 19
    TRISAbits.TRISA1 = 0;   // output pin 18
    TRISAbits.TRISA2 = 0;   // output pin 17
    TRISAbits.TRISA4 = 0;   // output pin 3
    
    /* internal clock setup*/
    OSCCONbits.IRCF2 = 1;           // 4 MHz clock configuration
    OSCCONbits.IRCF1 = 1;
    OSCCONbits.IRCF0 = 0;
    
    PORTC = 0x00;           // all port outputs low
    PORTA = 0x00;
    
}
