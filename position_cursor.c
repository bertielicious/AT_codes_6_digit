#include <xc.h>
#include "pulse_E.h"
#include "config.h"
void position_cursor (uchar xy)
{
uchar hi_nib, lo_nib; // hi_nib is most significant nibble
hi_nib = xy & 0xf0; // split data into high nibble
lo_nib = (xy & 0x0f) >> 4; // split data into low nibble, and move four bits right
RS = 0; // lcd command mode
PORTB = hi_nib;
pulse_E();
PORTB = lo_nib;
pulse_E();
}
