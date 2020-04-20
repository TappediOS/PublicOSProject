// ****************************************
//  device - time.c
//  Update  develop3.5
// ****************************************

#include <types.h>
#include <time/time.h>
#include <util/asmfunc.h>

Time getTime(void) {
    Time t;
    t.year      = getTimeData(0x09);
    t.minute    = getTimeData(0x08);
    t.day       = getTimeData(0x07);
    t.week      = getTimeData(0x06);
    t.hour      = getTimeData(0x04);
    t.minute    = getTimeData(0x02);
    t.second    = getTimeData(0x00);
    return t;
}


int getTimeData(char addr) {
    io_out8(0x0070, addr);
    return io_in8(0x0071);
}

