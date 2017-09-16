#include <xc.h>
#include "init_ports.h"
#include "init_eusart.h"
#include "config.h"
#include<stdbool.h>
#include "lcdData.h"
uchar get_at_code(void)

{
    
    uchar input;
    uchar i = 0;
    uchar AT[2] = {0x41, 0x54};     // array for characters A T
    lcdData(0xc0, 0);   // move cursor to starting position 0xc0 (2nd line of LCD first space)
    
    for (i = 0; i < 2; i++)// index the two elements of the array AT
    {
        lcdData(AT[i], 1);  // print AT on LCD 
        at_codes[i] = AT[i];// copy A and T into the forst two elements of array at_codes
    }                       // at_codes is an array which will contain 6 characters to send to the EUSART for serial transmission to ESP8266 module
    
    static uchar AT_length = 0; 
    while(AT_length < 4)    // max length of AT code is 6 ie AT plus 4 additional characters
    {
        lcdData(0xc2 + AT_length,0);// position the cursor on second line at third position _ AT-Length(increments by one every time loop executed )
        input = *ptr1;              // input accepts value of ATphabet[] array pointed at by ptr1
        lcdData(input,1);
 start: while (UP !=0);     // wait for user input
        while (UP!=1)             // execute next block of code if UP is zero i.e. UP button is pressed
            {
                __delay_ms(100); // de-bounce period
                lcdData(0xc2 + AT_length,0);// position lcd data at row two, position three
                ptr1++; // move pointer to the next character in ATphabet[]]
                input = *ptr1;// assign value pointed to by ptr1 to input
                lcdData(input,1);// write input value to LCD
                __delay_ms(500); // reaction time
            }
        while (DOWN !=0)      // wait for user input
        {
            if (ENTER !=1)    //  goto end if ENTER = 0
            {
                goto end;
            }
        }
       while (DOWN !=1) // while down button is pressed
            {
                __delay_ms(100); // de-bounce period
                lcdData(0xc2 + AT_length,0);// position cursor at 2nd line 3rd position + AT_length
                ptr1--; // decrement pointer to go backwards in ATphabet
                input = *ptr1;// assign value pointed to by ptr1 to input
                lcdData(input,1);// write input value to LCD
                __delay_ms(500); // reaction time
            }
           
        
 end:  while(ENTER !=0)// wait while enter button is not pressed
        {
            if(UP !=1 || DOWN !=1)
            {
                goto start;
            } 
        }
        
        
        if(ENTER !=1)
        {
            at_codes[AT_length + 2] = input;
            i++;
            
        }
      
        AT_length++;
        ptr1 = &ATphabet[0];
        at_codes[6] = 0x0d;// CR - carriage return
        at_codes[7] = 0x0a;// LF - line feed
    }  
}
