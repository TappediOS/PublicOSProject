// *************************************
//  memory - interrupt.c
//  Update  develop3.0
// *************************************

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
    io_out8(PIC0_OCW2, PIC_EOI);
    io_out8(PIC1_OCW2, PIC_EOI);
    drawString(5, 50, "Keyboard Interrupt", 0xFFFFFF);
}

