// ************************************
//  graphic - graphic.h
//  Update  develop2.1
// ************************************

#ifndef __GRAPHIC__
#define __GRAPHIC__

// structure
typedef struct GraphicInfo {
    unsigned long *vram;
    unsigned short int width;
    unsigned short int height;
} GraphicInfo;

// global paramater
GraphicInfo *gInfo = (GraphicInfo *)0x100000;

// init.c
void initGraphic(void);

// simple.c
int drawRectangle(int sx, int sy, int width, int height, unsigned long color);
int drawCircle(int cx, int cy, int r, unsigned long color);

// string.c
int drawCharacter(int sx, int sy, char c, unsigned long color);
int drawString(int sx, int sy, char *s, unsigned long color);

#include "init.c"
#include "simple.c"
#include "string.c"


#endif  // __GRAPHIC__

