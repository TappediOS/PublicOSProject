// *************************************
//  memory - interrupt.c
//  Update  develop3.0
// *************************************

#include <event/event.h>
#include <memory/interrupt.h>
#include <util/stdio.h>
#include <graphic/graphic.h>
#include <util/asmfunc.h>

void emptyHandler(void) {
    drawString(10, 50, "HLT", 0xFFFFFF);
    while(1) {
        asm("hlt");
    }
}

void keyboardHandler(void) {
    unsigned char data;
    data = io_in8(0x60);
    if (data > 0x80) {
        // putEvent(&event, EVENT_KEYRELEASED, (unsigned long long)(data - 0x80), 0x00);
    }
    else {
        putEvent(&event, EVENT_KEYPRESSED, (unsigned long long)data, 0x00);
    }
    io_out8(PIC0_OCW2, 0x61);
}

