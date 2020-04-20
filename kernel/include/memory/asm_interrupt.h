// ***********************************
//  include - memory - asm_interrupt.h
//  Update  develop3.0
// ***********************************

#include <types.h>

#ifndef __ASM_INTERRUPT__
#define __ASM_INTERRUPT__

extern void asmEmptyHandler(void);
extern void asmKeyboardHandler(void);
extern void asmMouseHandler(void);

#endif  // __ASM_INTERRUPT__
