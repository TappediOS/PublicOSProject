// **************************************
//  include - memory - interrupt.h
//  Update  develop3.4
// **************************************

#include <types.h>

#ifndef __INTERRUPT__
#define __INTERRUPT__

// port define
#define PIC0_ICW1 0x0020
#define PIC0_OCW2 0x0020
#define PIC0_IMR 0x0021
#define PIC0_ICW2 0x0021
#define PIC0_ICW3 0x0021
#define PIC0_ICW4 0x0021
#define PIC1_ICW1 0x00a0
#define PIC1_OCW2 0x00a0
#define PIC1_IMR 0x00a1
#define PIC1_ICW2 0x00a1
#define PIC1_ICW3 0x00a1
#define PIC1_ICW4 0x00a1

#define PIC_EOI 0x20


// interrupt define
#define INTERRUPT_NONE      0
#define INTERRUPT_TIMER     1
#define INTERRUPT_KEYBOARD  2

#define INTERRUPT_MOUSE     3

extern FIFO fifo;

void emptyHandler(void);

void timerHandler(void);
void keyboardHandler(void);
void mouseHandler(void);

#endif  // __INTERRUPT__
