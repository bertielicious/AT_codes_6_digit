/* 
 * File:   config.h
 * Author: Phil
 *
 * Created on 20 August 2017, 19:19
 */

#ifndef CONFIG_H
#define	CONFIG_H

#ifdef	__cplusplus
extern "C" {
#endif

// PIC16F690 Configuration Bit Settings

// 'C' source line config statements
#include <xc.h>
// CONFIG
#pragma config FOSC = INTRCIO   // Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA4/OSC2/CLKOUT pin, I/O function on RA5/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select bit (MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown-out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#define _XTAL_FREQ 4000000      // 4MHz internal clock

#define RS PORTCbits.RC0        // RS = 1 = display data, 0 = accept Instruction  pin 16
#define E PORTCbits.RC1         // E enable write pin 15
#define D4 PORTAbits.RA0        // D4 (LSB) pin 19
#define D5 PORTAbits.RA1        // D5 pin 18
#define D6 PORTAbits.RA2        // D6 pin 17
#define D7 PORTAbits.RA4        // D7 (MSB) pin 3
#define UP PORTCbits.RC2         // UP ATphabet input selection switch pin 14
#define DOWN PORTCbits.RC3       // DOWN ATphabet input selection switch pin 7
#define ENTER PORTCbits.RC4     // ENTER key pin 6
#define RX PORTBbits.RB5        // RX pin 12 of 16F690
#define TX PORTBbits.RB7        // TX pin 10 of 16F690
typedef char uchar;            // unsigned char shorthand

const uchar ATphabet[29] = {0x41, 0x54, 0x2b, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49,
0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x4f, 0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5a};

uchar *ptr1 = &ATphabet[0];
uchar at_codes[8];  // 6 AT characters plus CR and LF = 8 elements in total
const uchar at_code[] = "AT, AT+RST, AT+GMR, AT+GSLP ";
#ifdef	__cplusplus
}
#endif

#endif	/* CONFIG_H */

