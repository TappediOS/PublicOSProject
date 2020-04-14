// ***********************************
//  core - global.h
//  Update  develop3.0
// ***********************************

#include <types.h>

// message
unsigned char mflag = 0;
char mes[128];

// graphic
GraphicInfo *gInfo = (GraphicInfo *)0x100000;

// gdtidt
SEGMENT_DESCRIPTOR  *GDT = (SEGMENT_DESCRIPTOR *)0x0080;
GATE_DESCRIPTOR     *IDT = (GATE_DESCRIPTOR *)0x13000;

