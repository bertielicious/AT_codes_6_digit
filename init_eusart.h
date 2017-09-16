/* 
 * File:   init_eusart.h
 * Author: Phil
 *
 * Created on 03 September 2017, 12:25
 */

#ifndef INIT_EUSART_H
#define	INIT_EUSART_H

#ifdef	__cplusplus
extern "C" {
#endif
#define  BAUD 2400
#define BAUDSETTING (int)(_XTAL_FREQ/(64/ BAUD))
void init_eusart(void);


#ifdef	__cplusplus
}
#endif

#endif	/* INIT_EUSART_H */

