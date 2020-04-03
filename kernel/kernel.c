// ****************************************
//      kernel.c
//  Update  develop2.0
// ****************************************

#include "graphic/graphic.h"

int kernel_main() {
    drawRectangle(0, 0, gInfo->width, gInfo->height, 0x00000000);

    drawString(20, 0, "Start", 0xFFFFFF);
    drawString(20, 20, "Hello, World!!", 0xFFFFFF);
    drawString(20, 40, "Test String", 0xFFFFFF);

    while (1);
    return 0;
}
