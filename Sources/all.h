/******************************************************************************
 * all.h
 ******************************************************************************/
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

/******************************************************************************
*  C U S T O M    D A T A    T Y P E S
******************************************************************************/
#define uint8_t   unsigned char
#define bool      unsigned char
#define uint16_t  unsigned short
#define uint32_t  unsigned long
#define int8_t    signed char
#define int16_t   signed short
#define int32_t   signed long


/******************************************************************************
*  G L O B A L   M A C R O   D E F I N I T I O N S
******************************************************************************/
#ifndef bit
#define bit(x)  (1 << (x))
#endif

#endif   // #ifndef _ALL_H_
