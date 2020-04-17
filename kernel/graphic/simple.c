// ************************************
//  graphic - simple.c
//  Update  develop2.1
// ************************************

#include <graphic/graphic.h>

int drawPoint(const unsigned int sx, const unsigned int sy, const unsigned long color) {
    gInfo->vram[sy * gInfo->width + sx] = color;
    return 0;
}

int drawRectangle(const unsigned int sx, const unsigned int sy,
        const unsigned int width, const unsigned int height,
        const unsigned long color) {
    unsigned int x, y;
    for (y = sy; y < sy + height; y++) {
        for (x = sx; x < sx + width; x++) {
            gInfo->vram[y * gInfo->width + x] = color;
        }
    }
    return 0;
}

int drawCircle(const unsigned int cx, const unsigned int cy, const unsigned int r, const unsigned long color) {
    unsigned int x, y;
    for (y = cy -r; y <= cy +r; y++) {
        for (x = cx -r; x <= cx +r; x++) {
            if ((y-cy)*(y-cy) + (x-cx)*(x-cx) <= r*r) {
                gInfo->vram[y * gInfo->width + x] = color;
            }
        }
    }
    return 0;
}


