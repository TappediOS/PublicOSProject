// ****************************************
//  memory - gdtidt.c
//  Update  develop3.0
// ****************************************

#include <types.h>

#include <memory/gdtidt.h>

#include <memory/interrupt.h>
#include <memory/asm_interrupt.h>
#include <memory/fault.h>
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
    IDT[0x00] = makeGateDescriptor((unsigned long long)asmDeHandler);
    IDT[0x01] = makeGateDescriptor((unsigned long long)asmDbHandler);
    IDT[0x02] = makeGateDescriptor((unsigned long long)asmNmiHandler);
    IDT[0x03] = makeGateDescriptor((unsigned long long)asmBpHandler);
    IDT[0x04] = makeGateDescriptor((unsigned long long)asmOfHandler);
    IDT[0x05] = makeGateDescriptor((unsigned long long)asmBrHandler);
    IDT[0x06] = makeGateDescriptor((unsigned long long)asmUdHandler);
    IDT[0x07] = makeGateDescriptor((unsigned long long)asmNmHandler);
    IDT[0x08] = makeGateDescriptor((unsigned long long)asmDfHandler);
    IDT[0x0A] = makeGateDescriptor((unsigned long long)asmTsHandler);
    IDT[0x0B] = makeGateDescriptor((unsigned long long)asmNpHandler);
    IDT[0x0C] = makeGateDescriptor((unsigned long long)asmSsHandler);
    IDT[0x0D] = makeGateDescriptor((unsigned long long)asmGpHandler);
    IDT[0x0E] = makeGateDescriptor((unsigned long long)asmPfHandler);
    IDT[0x10] = makeGateDescriptor((unsigned long long)asmMfHandler);
    IDT[0x11] = makeGateDescriptor((unsigned long long)asmAcHandler);
    IDT[0x12] = makeGateDescriptor((unsigned long long)asmMcHandler);
    IDT[0x13] = makeGateDescriptor((unsigned long long)asmXmHandler);
    IDT[0x20] = makeGateDescriptor((unsigned long long)asmTimerHandler);
    IDT[0x21] = makeGateDescriptor((unsigned long long)asmKeyboardHandler);
    IDT[0x2C] = makeGateDescriptor((unsigned long long)asmMouseHandler);
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
