// ************************************
//  graphic - simple.c
//  Update  develop2.1
// ************************************

#include "init.c"

#ifndef __GRAPHIC_SIMPLE__
#define __GRAPHIC_SIMPLE__

int drawRectangle(int sx, int sy, int width, int height, unsigned long color) {
    int x, y;
    for (y = sy; y < sy + height; y++) {
        for (x = sx; x < sx + width; x++) {
            gInfo->vram[y * gInfo->width + x] = color;
        }
    }
    return 0;
}

int drawCircle(int cx, int cy, int r, unsigned long color) {
    int x, y;
    for (y = cy -r; y <= cy +r; y++) {
        for (x = cx -r; x <= cx +r; x++) {
            if ((y-cy)*(y-cy) + (x-cx)*(x-cx) <= r*r) {
                gInfo->vram[y * gInfo->width + x] = color;
            }
        }
    }
    return 0;
}

#endif  // __GRAPHIC_SIMPLE__

