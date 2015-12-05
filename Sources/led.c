/******************************************************************************
 * led.c
 ******************************************************************************/
#include "all.h"
#include "led.h"

/******************************************************************************
 * ledInit
 ******************************************************************************/
void ledInit(void) {
  // macros defined in led.h
  RED_LED_SET_OUTPUT();
  GREEN_LED_SET_OUTPUT();
  YELLOW_LED_SET_OUTPUT();

  RED_LED_OFF();
  GREEN_LED_OFF();
  YELLOW_LED_OFF();
}

/******************************************************************************
 * vParTestToggleLED - FreeRTOS flash demo routine
 ******************************************************************************/
void vParTestToggleLED(uint8_t val) {
  switch(val) {
    case 0:
      RED_LED_TOGGLE();
      break;
    case 1:
      GREEN_LED_TOGGLE();
      break;
    case 2:
      YELLOW_LED_TOGGLE();
      break;
  }
}