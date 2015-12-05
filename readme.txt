//------------------------------------------------------------------------
//  readme.txt
//------------------------------------------------------------------------
This project is a very minimal contributed demo port of a Technological Arts
EsduinoXtreme board using the special edition of the CodeWarrior IDE for S12...

http://cache.freescale.com/lgfiles/devsuites/HC12/CW_HC12_v5.1_SPECIAL.exe

The Freescale MC9S12GA240 mcu on the EsduinoXtreme board requires this patch to
the IDE...

http://cache.freescale.com/lgfiles/updates/CWHC12/CW12_V5_1_HCS12_G240_SP.exe

Though the GA240 header is provided by the patch there are no Processor Expert
modules available for that mcu.  This port is a variation of the
HCS12_CodeWarrior_small port in the FreeRTOS repository but without Processor
Expert as well as the bug fix to port.c that enabled XIRQ and STOP in the CCR.

The png file FreeRTOS_s12ga240_paths.png shows the pathing used for the project
(Edit->Standard Settings...).  You will need to adjust the FreeRTOS paths for
your version or directory path.

The demo blinks three LEDs in separate tasks using the installed LED at pin 0 of
port J plus two LEDs added at pins 3 & 4 of port T which are easily accessed
from J3.
