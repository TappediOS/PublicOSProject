// ***********************************
//  include - memory - asm_interrupt.h
//  Update  develop3.6
// ***********************************

#include <types.h>

#ifndef __ASM_INTERRUPT__
#define __ASM_INTERRUPT__

extern void asmTimerHandler(void);
extern void asmKeyboardHandler(void);
extern void asmMouseHandler(void);

#endif  // __ASM_INTERRUPT__
