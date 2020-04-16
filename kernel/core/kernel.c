// ********************************************
//  core - kernel.c
//  Update  develop3.0
// ********************************************

#include <types.h>

#include <console/console.h>
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

    initConsole(&console);
    drawRectangle(10, 10, CONSOLE_ROW * 8 + 2, CONSOLE_LINE * 16 + 2, 0xFFFFFF);
    drawConsole(&console);

    initFIFO(&fifo);
    nFIFO f;

    char str[256];


    while (1) {
        f = getFIFO(&fifo);
        switch(f.low) {
        case INTERRUPT_NONE:
            break;
        case INTERRUPT_KEYBOARD:
            sprintf(str, "KEYBOARD : 0x%x", f.high);
            inputConsole(&console, str);
            drawConsole(&console);
            break;
        case INTERRUPT_MOUSE:
            sprintf(str, "MOUSE : %x", f.high);
            inputConsole(&console, str);
            drawConsole(&console);
            break;
        default:
            sprintf(str, "UNDEFINED EVENT");
            inputConsole(&console, str);
            drawConsole(&console);
            break;
        }
    }

    return;
}

