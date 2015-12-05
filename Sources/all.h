#ifndef _ALL_H_
#define _ALL_H_

#include <hidef.h>
#include "derivative.h"


/******************************************************************************
*  G L O B A L    D E F I N I T I O N S
******************************************************************************/
#ifndef  NULL
#define  NULL  ((void *)0)
#endif

#define TRUE  1
#define true  1
#define FALSE 0
#define false 0

#define READ  1
#define WRITE 0

#define ZERO_TERM 0

/******************************************************************************
*  C U S T O M    D A T A    T Y P E S
******************************************************************************/
#define uint8_t   unsigned char
#define bool    unsigned char
#define uint16_t  unsigned short
#define uint32_t  unsigned long
#define int8_t    signed char
#define int16_t   signed short
#define int32_t   signed long

// Big endian unions for 16 and 32 bit types
typedef union {
  uint16_t   w;
  struct {
    uint8_t  h;
    uint8_t  l;
  } b;
} u_union_16_t;

#define uu16_t u_union_16_t

typedef union {
  int16_t    w;
  struct {
    int8_t   h;
    int8_t   l;
  } b;
} s_union_16_t;

#define su16_t s_union_16_t

// Error blocks
enum {
  GLOBAL_ERR = 0,
  CAN_ERR,
  CMD_ERR,
  SRV_ERR,
  EVT_ERR,
  ATD_ERR,
  FIL_ERR,
  EEP_ERR,
  SCI_ERR,
  /***********/
  MAX_ERR_BLOCK
};

// Range of each error block
#define ERROR_RANGE 0x100

// Error block start codes
#define  GLOBAL_ERR_START  0                          // 0x0000
#define  CAN_ERR_START    (0 - CAN_ERR * ERROR_RANGE) // 0xFF00 - errors in can.h
#define  CMD_ERR_START    (0 - CMD_ERR * ERROR_RANGE) // 0xFE00 - errors in flsc.h
#define  SRV_ERR_START    (0 - SRV_ERR * ERROR_RANGE) // 0xFD00 - errors in flsc.h
#define  EVT_ERR_START    (0 - EVT_ERR * ERROR_RANGE) // 0xFC00 - errors in flsc.h
#define  ATD_ERR_START    (0 - ATD_ERR * ERROR_RANGE) // 0xFB00 - errors in flsc.h
#define  FILE_ERR_START   (0 - FIL_ERR * ERROR_RANGE) // 0xFA00 - errors in flsc.h
#define  EE_ERR_START     (0 - EEP_ERR * ERROR_RANGE) // 0xF900 - errors in flsc.h
#define  SCI_ERR_START    (0 - SCI_ERR * ERROR_RANGE) // 0xF800 - errors in sci.h

// Global return values
#define  APP_ESCAPE             (GLOBAL_ERR_START + 2)  // 0x0002 (used by menuing in main.c)
#define  APP_RUNNING            (GLOBAL_ERR_START + 1)  // 0x0001
#define  APP_SUCCESS            (GLOBAL_ERR_START)      // 0x0000
#define  APP_ERR_FAIL           (GLOBAL_ERR_START - 1)  // 0xFFFF
#define  APP_ERR_INVALID_PARAM  (GLOBAL_ERR_START - 2)  // 0xFFFE
#define  APP_ERR_INT_RESOURCE   (GLOBAL_ERR_START - 3)  // 0xFFFD
#define  APP_ERR_TIMEOUT        (GLOBAL_ERR_START - 4)  // 0xFFFC

#define  ENTER_CRITICAL_REGION()    __asm("tpa\n staa save_ccr\n sei")
#define  LEAVE_CRITICAL_REGION()    __asm("ldaa save_ccr\n tap")
#define  CLI()                      __asm("cli")
#define  SEI()                      __asm("sei")
#define  NOP()                      __asm("nop")

// Ascii defines
#define BS   0x08 //back space
#define LF   0x0A //line feed
#define FF   0x0C //form feed
#define CR   0x0D //carriage return
#define ESC  0x1B //escape
#define SP   0x20 //space


/******************************************************************************
*  G L O B A L   M A C R O   D E F I N I T I O N S
******************************************************************************/
#ifndef bit
#define bit(x)  (1 << (x))
#endif

#endif   // #ifndef _ALL_H_
