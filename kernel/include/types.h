// **************************************
//  include - types.h
//  Update  develop3.1
// **************************************

#ifndef __TYPES__
#define __TYPES__

// event
typedef struct Event {
    unsigned int id;
    unsigned long long low;
    unsigned long long high;
} Event;

typedef struct EventMan {
    Event event[64];
    unsigned char size;
    unsigned char read;
    unsigned char write;
} EventMan;

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

#endif  // __TYPES__
