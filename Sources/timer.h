/******************************************************************************
*
* Filename:     timer.h
*
* Copyright (c) Robert Milne 2011  All rights reserved.
*
******************************************************************************/
#ifndef _TIMER_H_
#define _TIMER_H_

#include "all.h"  //typedefs


/******************************************************************************
*  E X P O R T E D    D A T A    T Y P E S
******************************************************************************/
// timer stamp structure
typedef struct {
  uint32_t   start_time;    // Start time
  uint32_t   elapsed_time;  // Elapsed time = current time - start time
} timer_stamp_t;


/******************************************************************************
*  E X P O R T E D    F U N C T I O N    P R O T O T Y P E S
******************************************************************************/
void timInit      (void);
void timStamp     (timer_stamp_t *timer_stamp);
void timElapsed   (timer_stamp_t *timer_stamp);
void timDelay     (uint32_t ticks);
void TickTimer    (void);

// Required by port.c
uint8_t TickTimer_Enable(void);
int  TickTimer_SetFreqHz (uint16_t freq);

#endif  // #ifndef _TIMER_H_
