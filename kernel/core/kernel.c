// ********************************************
//  core - kernel.c
//  Update  develop3.0
// ********************************************

#include <types.h>

#include <console/console.h>
#include <device/mouse.h>
#include <graphic/graphic.h>
#include <memory/gdtidt.h>
#include <memory/device.h>
#include <memory/interrupt.h>
#include <time/time.h>
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

    initConsole(&console);
    drawRectangle(10, 20, CONSOLE_ROW * 8 + 2, CONSOLE_LINE * 16 + 2, 0xFFFFFF);
    drawConsole(&console);

    initIdt();
    initPic();
    initTimer();
    initKeyBoard();
    initMouse();
    io_out8(PIC0_IMR, 0xF8);
    io_out8(PIC1_IMR, 0xEF);
    io_sti();

    initMouseInfo(&mouse);

    nFIFO f;
    initFIFO(&fifo);

    char str[256];
    int ret = 0;
    Time t;
    int cnt = 0, sec = 0;

    while (1) {
        f = getFIFO(&fifo);
        switch(f.low) {
        case INTERRUPT_NONE:
            break;
        case INTERRUPT_TIMER:
            if (cnt++ > 50) {
                cnt = 0;
                t = getTime();
                sprintf(str, "RTC : %d:%d:%d", t.hour, t.minute, t.second);
                drawRectangle(20, 550, 200, 25, 0xFF0000);
                drawString(22, 552, str, 0xFFFF00);
            }
            break;
        case INTERRUPT_KEYBOARD:
            sprintf(str, "KEYBOARD : 0x%x", f.high);
            inputConsole(&console, str);
            drawConsole(&console);
            break;
        case INTERRUPT_MOUSE:
            inputMouseInfo(&mouse, (char)(f.high));
            ret = decodeMouseInfo(&mouse);
            if (ret == 0xFF) {
                ;       // error
            }
            else if (ret == 0x00) {
                drawConsole(&console);
                drawMouse(&mouse);
            }
            else {
                sprintf(str, "MOUSE : %x", ret);
                inputConsole(&console, str);
                drawConsole(&console);
                drawMouse(&mouse);
            }
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

