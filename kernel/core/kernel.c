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
#include <util/fifo.h>

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
    initMouse();
    io_out8(PIC0_IMR, 0xF9);
    io_out8(PIC1_IMR, 0xEF);
    io_sti();

    drawRectangle(70, 300, 50, 100, 0xFF00FF);

    unsigned long long color = 0x000000;
    int ly = 5;
    initFIFO(&fifo);

    char str[256];
    nFIFO f;

    while (1) {
        f = getFIFO(&fifo);
        switch(f.low) {
        case INTERRUPT_NONE:
            color = (color + 0x08) % 0x1000000;
            drawRectangle(10, 300, 50, 100, color);
            break;
        case INTERRUPT_KEYBOARD:
            sprintf(str, "KEYPRESSED : %x", f.high);
            drawString(80, ly, str, 0xFFFFFF);
            ly += 18;
            break;
        case INTERRUPT_MOUSE:
            sprintf(str, "MOUSE : %x", f.high);
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

