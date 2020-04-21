// **************************************
//  memory - device.c
//  Update  develop3.0
// **************************************

#include <types.h>
#include <memory/device.h>
#include <memory/interrupt.h>
#include <util/asmfunc.h>

// debug ->
#include <util/stdio.h>
#include <graphic/graphic.h>
extern Console console;
char str[64];
// <- debug

// 11932 -> 100Hz
void initTimer(void) {
    io_out8(PIT_CTRL, 0x34);
    io_out8(PIT_CNT0, 0x9C);
    io_out8(PIT_CNT0, 0x2E);
}

void initKeyBoard(void) {
    waitKeyboardSendReady();
    io_out8(0x0064, 0x60);
    waitKeyboardSendReady();
    io_out8(0x0060, 0x47);
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
