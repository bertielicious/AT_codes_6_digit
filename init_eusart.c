#include <xc.h>
#include "init_eusart.h"
#include "config.h"

void init_eusart(void)
{
    /* turn off interrupts and setup TX, RX for EUSART*/
    
    TRISBbits.TRISB5 = 1;  // RX input pin 12
    TRISBbits.TRISB7 = 0;  // TX output pin 10
    TRISCbits.TRISC0 = 0;   // main() heartbeat monitor for diagnostic purposes
    RX = 1;
    TX = 0; // set RX and TX pins to 1 and 0 respectively
    
    /*init ESUART module for 8 bit transmission at 2400 baud*/
    TXSTAbits.TXEN = 1; // enables TX of EUSART
    TXSTAbits.SYNC = 0; // configures EUSART for asynchronous comms
    RCSTAbits.SPEN = 1; // enables EUSART and configures TX pin as an output
    
    SPBRGbits.BRG7 = 0;// set baud rate rate to 2400 = d'25 or hex 0x19
    SPBRGbits.BRG6 = 0;// or binary 0b00011001
    SPBRGbits.BRG5 = 0;
    SPBRGbits.BRG4 = 1;
    SPBRGbits.BRG3 = 1;
    SPBRGbits.BRG2 = 0;
    SPBRGbits.BRG1 = 0;
    SPBRGbits.BRG0 = 1;
    
    BAUDCTLbits.BRG16 = 0;  // 16 bit Baud rate timer off, we are using 8 bit timer (default))
    TXSTAbits.BRGH = 0;     // low speed asynchronous mode selected, as our baud rate is 2400
    TXSTAbits.TX9 = 0;      // 8 bit transmission selected, not 9 bit */
    SPBRGH = 0x00;          //we are not using the 16 bit register to determine baud rate
    INTCON = 0x00;          // disable interrupts
    
    /*init ESUART module for 8 bit reception at 2400 baud*/
    RCSTAbits.CREN = 1;     // Continuous Receive Enable Bit is set, which enables the receiver
    RCSTAbits.RX9 = 0;      // 8 bit reception
}