// *****************************************
//  include - memory - gdtidt.h
//  Update  develop3.0
// *****************************************

#include <types.h>

#ifndef __GDTIDT__
#define __GDTIDT__


// global param
extern SEGMENT_DESCRIPTOR   *GDT;
extern GATE_DESCRIPTOR      *IDT;

// asm_gdtidt.S
extern void loadGdt(void);
extern void loadIdt(void);

// gdtidt.c
void initGdt(void);
void initIdt(void);
void initPic(void);
GATE_DESCRIPTOR makeGateDescriptor(unsigned long long addr);

#endif  // __GDTIDT__
