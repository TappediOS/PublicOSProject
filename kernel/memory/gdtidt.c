// ****************************************
//  memory - gdtidt.c
//  Update  develop3.0
// ****************************************

#include <types.h>

#include <memory/gdtidt.h>

#include <memory/interrupt.h>
#include <memory/asm_interrupt.h>
#include <util/asmfunc.h>

extern void loadGdt();

void initGdt(void) {
    GDT[0] = 0x0000000000000000;
    GDT[1] = 0x00AF9A000000FFFF;
    GDT[2] = 0x00CF93000000FFFF;
    loadGdt();
}

#include <graphic/graphic.h>

#include <util/stdio.h>
unsigned long long idtr[2];

void initIdt(void) {
    int i;
    for (i = 0; i < 256; i++)
        IDT[i] = makeGateDescriptor((unsigned long long)asmEmptyHandler);
    IDT[0x21] = makeGateDescriptor((unsigned long long)asmKeyboardHandler);
    loadIdt();
}

void initPic(void) {
    io_out8(PIC0_IMR, 0xFF);
    io_out8(PIC1_IMR, 0xFF);

    io_out8(PIC0_ICW1, 0x11);
    io_out8(PIC0_ICW2, 0x20);
    io_out8(PIC0_ICW3, 1 << 2);
    io_out8(PIC0_ICW4, 0x01);

    io_out8(PIC1_ICW1, 0x11);
    io_out8(PIC1_ICW2, 0x28);
    io_out8(PIC1_ICW3, 2);
    io_out8(PIC1_ICW4, 0x01);

    char str[256];
    sprintf(str, "initPIC master : %x", io_in8(PIC1_IMR));
    drawString(10, 75, str, 0xFFFFFF);
    return;
}

GATE_DESCRIPTOR makeGateDescriptor(unsigned long long addr) {
    GATE_DESCRIPTOR gateDesc;
    gateDesc.offset_00_15   = (unsigned long long)addr;
    gateDesc.selector       = 0x08;
    gateDesc.type           = 14;
    gateDesc.p              = 1;
    gateDesc.offset_31_16   = (unsigned long long)addr >> 16;
    gateDesc.offset_63_32   = (unsigned long long)addr >> 32;
    return gateDesc;
}
