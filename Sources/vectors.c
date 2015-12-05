#include "all.h"

extern void _EntryPoint(void); // Entry point after Reset
extern void vPortYield(void);
extern void vPortTickInterrupt(void); // port.c
#ifdef EN_SCI
extern void sciHandler(void); // sci.c
#endif

/******************************************************************************
*  U N U S E D   I S R   T R A P S
******************************************************************************/
__interrupt void isrTrap(void) {
  NOP();
}
__interrupt void irqTrap(void) {
  NOP();
}
__interrupt void xirqTrap(void) {
  NOP();
}
__interrupt void swiTrap(void) {
  NOP();
}
__interrupt void unimpTrap(void) {
  NOP();
}
__interrupt void copTrap(void) {
  NOP();
}
__interrupt void cmfTrap(void) {
  NOP();
}


void (* const interrupt_vectors[])() @0xff80 =
{
  isrTrap,            // $FF80 vector 63  Spurious interrupt
  isrTrap,            // $FF82 vector 62  Port AD interrupt
  isrTrap,            // $FF84 vector 61  ADC compare interrupt
  isrTrap,            // $FF86 vector 60  Reserved
  isrTrap,            // $FF88 vector 59  API
  isrTrap,            // $FF8A vector 58  VREG LVI
  isrTrap,            // $FF8C vector 57  Reserved
  isrTrap,            // $FF8E vector 56  Port P
  isrTrap,            // $FF90 vector 55  Reserved
  isrTrap,            // $FF92 vector 54  Reserved
  isrTrap,            // $FF94 vector 53  Reserved
  isrTrap,            // $FF96 vector 52  Reserved
  isrTrap,            // $FF98 vector 51  Reserved
  isrTrap,            // $FF9A vector 50  Reserved
  isrTrap,            // $FF9C vector 49  Reserved
  isrTrap,            // $FF9E vector 48  Reserved
  isrTrap,            // $FFA0 vector 47  Reserved
  isrTrap,            // $FFA2 vector 46  Reserved
  isrTrap,            // $FFA4 vector 45  Reserved
  isrTrap,            // $FFA6 vector 44  Reserved
  isrTrap,            // $FFA8 vector 43  Reserved
  isrTrap,            // $FFAA vector 42  Reserved
  isrTrap,            // $FFAC vector 41  Reserved
  isrTrap,            // $FFAE vector 40  Reserved
  isrTrap,            // $FFB0 vector 39  CAN Transmit
  isrTrap,            // $FFB2 vector 38  CAN Receive
  isrTrap,            // $FFB4 vector 37  CAN Errors
  isrTrap,            // $FFB6 vector 36  CAN Wake-up
  isrTrap,            // $FFB8 vector 35  Flash cmd
  isrTrap,            // $FFBA vector 34  FLASH error
  isrTrap,            // $FFBC vector 33  SPI2
  isrTrap,            // $FFBE vector 32  SPI1
  isrTrap,            // $FFC0 vector 31  Reserved
  isrTrap,            // $FFC2 vector 30  SCI2
  isrTrap,            // $FFC4 vector 29  Reserved
  isrTrap,            // $FFC6 vector 28  PLL lock interrupt
  isrTrap,            // $FFC8 vector 27  Oscillator status interrupt
  isrTrap,            // $FFCA vector 26  Reserved
  isrTrap,            // $FFCC vector 25  ACMP
  isrTrap,            // $FFCE vector 24  PortJ
  isrTrap,            // $FFD0 vector 23  Reserved
  isrTrap,            // $FFD2 vector 22  ADC
  isrTrap,            // $FFD4 vector 21  SCI1
#ifdef EN_SCI
  sciHandler,         // $FFD6 vector 20  SCI0
#else
  isrTrap,            // $FFD6 vector 20  SCI0
#endif
  isrTrap,            // $FFD8 vector 19  SPI0
  isrTrap,            // $FFDA vector 18  Pulse Accumulator A Input Edge
  isrTrap,            // $FFDC vector 17  Pulse Accumulator A Overflow
  isrTrap,            // $FFDE vector 16  Timer Overflow
  isrTrap,            // $FFE0 vector 15  Timer Channel 7
  isrTrap,            // $FFE2 vector 14  Timer Channel 6
  isrTrap,            // $FFE4 vector 13  Timer Channel 5
  isrTrap,            // $FFE6 vector 12  Timer Channel 4
  isrTrap,            // $FFE8 vector 11  Timer Channel 3
  isrTrap,            // $FFEA vector 10  Timer Channel 2
  isrTrap,            // $FFEC vector 09  Timer Channel 1
  vPortTickInterrupt, // $FFEE vector 08  Timer Channel 0
  isrTrap,            // $FFF0 vector 07  Real Time Interrupt
  irqTrap,            // $FFF2 vector 06  IRQ
  xirqTrap,           // $FFF4 vector 05  XIRQ
  vPortYield,         // $FFF6 vector 04  SWI
  unimpTrap,          // $FFF8 vector 03  Unimplement Instruction Trap
  copTrap,            // $FFFA vector 02  COP failure reset
  cmfTrap,            // $FFFC vector 01  Clock monitor fail reset
  _EntryPoint         // $FFFE vector 00  Reset vector
};
