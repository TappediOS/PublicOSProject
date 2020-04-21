// *************************************
//  memory - interrupt.c
//  Update  develop3.0
// *************************************

#include <memory/interrupt.h>
#include <util/stdio.h>
#include <graphic/graphic.h>
#include <util/asmfunc.h>
#include <util/fifo.h>

void emptyHandler(void) {
    drawString(10, 50, "HLT", 0xFFFFFF);
    while(1) {
        asm("hlt");
    }
}

void timerHandler(void) {
    putFIFO(&fifo, INTERRUPT_TIMER, 0x00);
    io_out8(PIC0_OCW2, 0x60);
}

void keyboardHandler(void) {
    unsigned char data;
    data = io_in8(0x60);
    putFIFO(&fifo, INTERRUPT_KEYBOARD, (int)data);
    io_out8(PIC0_OCW2, 0x61);
}

void mouseHandler(void) {
    unsigned char data;
    data = io_in8(0x60);
    putFIFO(&fifo, INTERRUPT_MOUSE, (int)data);
    io_out8(PIC1_OCW2, 0x64);
    io_out8(PIC0_OCW2, 0x62);
}
