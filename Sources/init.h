/******************************************************************************
 * init.h
 ******************************************************************************/
#ifndef __INIT_H__
#define __INIT_H__

#define IO_TYPE_DRIVE           0
#define IO_TYPE_SINK            1

#define RED_IO_TYPE            IO_TYPE_DRIVE
#define RED_LED_PORT_DIR       DDRJ
#define RED_LED_PORT           PTJ
#define RED_LED_PIN            bit(0)

// LED macros
#define RED_LED_SET_OUTPUT()   (RED_LED_PORT_DIR |= RED_LED_PIN)
#if(RED_IO_TYPE == IO_TYPE_DRIVE)
  #define RED_LED_ON()         (RED_LED_PORT |= RED_LED_PIN)
  #define RED_LED_OFF()        (RED_LED_PORT &=~ RED_LED_PIN)
#else
  #define RED_LED_ON()         (RED_LED_PORT &=~ RED_LED_PIN)
  #define RED_LED_OFF()        (RED_LED_PORT |= RED_LED_PIN)
#endif
#define RED_LED_TOGGLE()       (RED_LED_PORT ^= RED_LED_PIN)

#define GREEN_IO_TYPE            IO_TYPE_DRIVE
#define GREEN_LED_PORT_DIR       DDRT
#define GREEN_LED_PORT           PTT
#define GREEN_LED_PIN            bit(3)

// LED macros
#define GREEN_LED_SET_OUTPUT()   (GREEN_LED_PORT_DIR |= GREEN_LED_PIN)
#if(GREEN_IO_TYPE == IO_TYPE_DRIVE)
  #define GREEN_LED_ON()         (GREEN_LED_PORT |= GREEN_LED_PIN)
  #define GREEN_LED_OFF()        (GREEN_LED_PORT &=~ GREEN_LED_PIN)
#else
  #define GREEN_LED_ON()         (GREEN_LED_PORT &=~ GREEN_LED_PIN)
  #define GREEN_LED_OFF()        (GREEN_LED_PORT |= GREEN_LED_PIN)
#endif
#define GREEN_LED_TOGGLE()       (GREEN_LED_PORT ^= GREEN_LED_PIN)

void board_init(void);

#endif // __INIT_H__
