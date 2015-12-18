/******************************************************************************
 * timer.h
 ******************************************************************************/
#ifndef _TIMER_H_
#define _TIMER_H_

#include "all.h"

/******************************************************************************
*  E X P O R T E D    F U N C T I O N    P R O T O T Y P E S
******************************************************************************/
// Required by port.c
uint8_t TickTimer_Enable    (void);
int     TickTimer_SetFreqHz (uint16_t freq);

#endif  // #ifndef _TIMER_H_
