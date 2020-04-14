// ***********************************
//  include - graphic - graphic.h
//  Update  develop3.0
// ***********************************

#include <types.h>

#ifndef __GRAPHIC__
#define __GRAPHIC__

// global param
extern GraphicInfo *gInfo;

// init.c
void initGraphic(void);

// simple.c
int drawRectangle(const unsigned int sx, const unsigned int sy, const unsigned int width, const unsigned int height, const unsigned long color);
int drawCircle(const unsigned int cx, const unsigned int cy, const unsigned int r, const unsigned long color);

// string.c
int drawCharacter(const unsigned int sx, const unsigned int sy, const unsigned char c, const unsigned long color);
int drawString(const unsigned int sx, const unsigned int sy, const char *s, const unsigned long color);

#endif  // __GRAPHIC__

