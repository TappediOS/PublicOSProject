// ********************************************
//  core - kernel.c
//  Update  develop3.0
// ********************************************

#include <types.h>

#include <event/event.h>
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

    drawRectangle(70, 300, 50, 100, 0xFF00FF);

    unsigned long long color = 0x000000;
    int ly = 5;
    Event e;

    char str[256];

    while (1) {
        e = getEvent(&event);
        switch(e.id) {
        case EVENT_NONE:
            color = (color + 0x08) % 0x1000000;
            drawRectangle(10, 300, 50, 100, color);
            break;
        case EVENT_KEYPRESSED:
            sprintf(str, "KEYPRESSED : %x", e.low);
            drawString(80, ly, str, 0xFFFFFF);
            ly += 18;
            break;
        case EVENT_KEYRELEASED:
            sprintf(str, "KEYRELEASED : %x", e.low);
            drawString(80, ly, str, 0xFFFFFF);
            ly += 18;
            break;
        default:
            drawString(80, ly, "UNDEFINED EVENT", 0xFFFFFF);
            ly += 18;
            break;
        }
    }
    return;
}

