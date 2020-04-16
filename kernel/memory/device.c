// **************************************
//  memory - device.c
//  Update  develop3.0
// **************************************

#include <types.h>
#include <memory/device.h>
#include <memory/interrupt.h>
#include <util/asmfunc.h>

// debug ->
#include <graphic/graphic.h>
// <- debug

void initKeyBoard(void) {
    waitKeyboardSendReady();
    io_out8(0x0064, 0x60);
    waitKeyboardSendReady();
    io_out8(0x0060, 0x47);

    drawString(5, 55, "initialize Keyboard", 0xFFFFFF);
    return;
}

void waitKeyboardSendReady(void) {
    while(1) {
        if ((io_in8(0x0064) & 0x02) == 0) {
            break;
        }
    }
}

void initMouse(void) {
    waitKeyboardSendReady();
    io_out8(0x64, 0xD4);
    waitKeyboardSendReady();
    io_out8(0x60, 0xF4);
}
