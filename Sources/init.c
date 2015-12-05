#include "all.h"
#include "led.h"
#include "timer.h"

extern void _Startup(void);

void _EntryPoint(void) {
  // Initialise PEE system clock for 24MHz (PEE = PLL Engaged External)
  // If XOSCLCP enabled (OSCE=1) fREF = fOSC / (REFDIV + 1) => 8MHz = 8MHz / 0 + 1
  // If PLL locked (LOCK=1)      fVCO = 2 × fREF × (SYNDIV + 1) => 48MHz = 2 * 8MHz * (2 + 1)
  // If PLL locked (LOCK=1)      fPLL = fVCO / (POSTDIV + 1) => 48MHz = 48MHz / (0 + 1)
  // If PLL selected (PLLSEL=1)  fbus = fPLL / 2 => 24MHz = 48MHz / 2
  CPMUSYNR = 0x02;          // SYNDIV = 2; VCOFRQ = 0 (48MHz)
  CPMUREFDIV = 0x80;        // REFDIV = 0; REFCLK = 6MHz < fREF <= 12MHz (OSCE=1)
  CPMUPOSTDIV = 0x00;       // POSTDIV = 0
  CPMUCLKS_PLLSEL = 1;      // PLLSEL = 1; RTI clock src = COP clock src = IRCCLK
  while(!CPMUCLKS_PLLSEL);  // Verify CPMUCLKS configuration
  CPMUOSC_OSCE = 1;         // Enable external oscillator
  while(!CPMUFLG_UPOSC);    // Wait for OSC to stabilise
  while(!CPMUFLG_LOCK);     // Wait for PLL to lock

  __asm  jmp _Startup;
}

void board_init(void) {
  timInit();
  ledInit();
  EnableInterrupts;
}
