// ********************************************
//  core - kernel.c
//  Update  develop3.0
// ********************************************

#include <types.h>

#include <graphic/graphic.h>
#include <memory/gdtidt.h>
#include <memory/device.h>
#include <memory/interrupt.h>
#include <util/stdio.h>
#include <util/asmfunc.h>

#include "global.h"

void kernel_init();
void kernel_main();

void kernel_init() {
    drawRectangle(0, 0, gInfo->width, gInfo->height, 0x000000);
    drawString(10, 5, "Hello, World!!", 0xFFFFFF);
    initGdt();
    drawString(10, 42, "KERNEL_MAIN ERROR", 0xFFFFFF);
}

void kernel_main() {
    initIdt();
    initPic();
    initKeyBoard();
    // initTimer();
    io_out8(PIC0_IMR, 0xFD);
    io_sti();

    drawRectangle(250, 300, 50, 100, 0xFF00FF);

    unsigned long long color = 0x000000;
    while (1) {
        color = (color + 0x08) % 0x1000000;
        drawRectangle(300, 300, 50, 100, color);
    }
    return;
}

