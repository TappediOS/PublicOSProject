// **************************************
//  include - types.h
//  Update  develop3.1
// **************************************

#ifndef __TYPES__
#define __TYPES__

// graphics
typedef struct GraphicInfo {
    unsigned long *vram;
    unsigned short int width;
    unsigned short int height;
} GraphicInfo;


// gdtidt
typedef unsigned long long SEGMENT_DESCRIPTOR;

typedef struct GATE_DESCRIPTOR {
    unsigned short offset_00_15;
    unsigned short selector;
    unsigned short ist      : 3;
    unsigned short _zero1   : 5;
    unsigned short type     : 4;
    unsigned short _zero2   : 1;
    unsigned short dpl      : 2;
    unsigned short p        : 1;
    unsigned short offset_31_16;
    unsigned int   offset_63_32;
    unsigned int   _reserved;
} GATE_DESCRIPTOR;


// util/fifo.c
typedef struct nFIFO {
    int low;
    int high;
} nFIFO;

typedef struct FIFO {
    nFIFO nfifo[64];
    unsigned char read;
    unsigned char write;
} FIFO;

#endif  // __TYPES__
