// *******************************
//  graphic - string.c
//  Update  develop2.1
// *******************************

#ifndef __GRAPHIC_STRING__
#define __GRAPHIC_STRING__

#include "font.h"

int drawCharacter(int sx, int sy, char c, unsigned long color) {
    int i, v;
    for (i = 0; i < 16; i++) {
        v = _fonts[c - 0x20][i];
        if (v & 0x80)   gInfo->vram[(sy+i) * gInfo->width + sx   ] = color;
        if (v & 0x40)   gInfo->vram[(sy+i) * gInfo->width + sx +1] = color;
        if (v & 0x20)   gInfo->vram[(sy+i) * gInfo->width + sx +2] = color;
        if (v & 0x10)   gInfo->vram[(sy+i) * gInfo->width + sx +3] = color;
        if (v & 0x08)   gInfo->vram[(sy+i) * gInfo->width + sx +4] = color;
        if (v & 0x04)   gInfo->vram[(sy+i) * gInfo->width + sx +5] = color;
        if (v & 0x02)   gInfo->vram[(sy+i) * gInfo->width + sx +6] = color;
        if (v & 0x01)   gInfo->vram[(sy+i) * gInfo->width + sx +7] = color;
    }
    return 0;
}

int drawString(int sx, int sy, char *s, unsigned long color) {
    int i;
    for (i = 0; s[i] != '\0'; i++) {
        drawCharacter(sx + i*9, sy, s[i], color);
    }
    return 0;
}

#endif  // __GRAPHIC_STRING__
