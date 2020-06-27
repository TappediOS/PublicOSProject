// ***********************************
//  core - global.h
//  Update  develop3.0
// ***********************************

#include <types.h>

// device - mouse.c
MouseInfo mouse;

// device - sata.c
HBA_MEMORY *hbaMemory;

// graphic
GraphicInfo *gInfo = (GraphicInfo *)0x100000;

// gdtidt
SEGMENT_DESCRIPTOR  *GDT = (SEGMENT_DESCRIPTOR *)0x0900;
GATE_DESCRIPTOR     *IDT = (GATE_DESCRIPTOR *)0x1000;

// memory management
nMEM_MAN nkernelMemMan[256];
MEM_MAN  kernelMemMan;

// fifo
FIFO fifo;

// console
Console console;

