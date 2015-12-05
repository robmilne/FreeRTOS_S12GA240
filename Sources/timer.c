/******************************************************************************
 * timer.c - TC0 based system timer
 ******************************************************************************/
#include "all.h"
#include "timer.h"


/******************************************************************************
*  S T A T I C    V A R I A B L E S
******************************************************************************/
// tick isr period (ioc0Handler)
uint16_t g_tick_period;

void timInit(void) {
  g_tick_period = 6000;
  TSCR1 = bit(7); // Enable timer
  TSCR2  = 0x02;  // Prescale = busclk/4 => 24MHz /4 = 6MHz
  TIOS  = bit(0); // Set IOC0 for output compare
  TFLG1 = bit(0); // clear interrupt flag
}

// Tick timer routines called from FreeRTOS
uint8_t TickTimer_Enable(void) {
  TC0 = TCNT + g_tick_period; // Initial compare value
  TIE = bit(0); // enable interrupt
  return 0;
}

int TickTimer_SetFreqHz(uint16_t freq) {
  // Check range
  if((freq > 1000) || (freq < 100))
    return -1;
  g_tick_period = (uint16_t)(6000000ul / (uint32_t)freq);
  return 0;
}
