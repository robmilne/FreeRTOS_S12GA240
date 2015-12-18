/******************************************************************************
 * main.c
 ******************************************************************************/
#include "all.h"
#include "init.h"

extern void vMain(void);

// Init peripherals and start FreeRTOS
void main(void) {
  board_init();
  __asm  jmp vMain;
  for(;;);
}
