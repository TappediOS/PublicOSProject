// *******************************
//  graphic - string.c
//  Update  develop2.1
// *******************************

#include <graphic/graphic.h>

#include "font.h"

int drawCharacter(const unsigned int sx, const unsigned int sy, const unsigned char c, const unsigned long color) {
    unsigned int i, v;
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

int drawString(const unsigned int sx, const unsigned int sy, const char *s, const unsigned long color) {
    unsigned int i = 0;
    do {
        drawCharacter(sx + i*9, sy, *s, color);
        i++;
        s++;
    } while(*s);
    return 0;
}

