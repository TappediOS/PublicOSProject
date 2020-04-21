// ****************************************
//  device - time.c
//  Update  develop3.5
// ****************************************

#include <types.h>
#include <time/time.h>
#include <util/asmfunc.h>


int updateRtc() {
    io_out8(0x0070, 0x0A);
    int status = io_in8(0x0071);
    return (status & 0x80);
}

Time getTime(void) {
    while (updateRtc());

    Time t;
    t.year      = getTimeData(0x09);
    t.month     = getTimeData(0x08);
    t.day       = getTimeData(0x07);
    t.week      = getTimeData(0x06);
    t.hour      = getTimeData(0x04);
    t.minute    = getTimeData(0x02);
    t.second    = getTimeData(0x00);


    int regB = getTimeData(0x0B);
    if (!(regB & 0x04)) {
        t.year      = changeTimeData(t.year);
        t.month     = changeTimeData(t.month);
        t.day       = changeTimeData(t.day);
        t.hour      = ((t.hour & 0x0F) + (((t.hour & 0x70) / 16) * 10)) | (t.hour & 0x80);
        t.minute    = changeTimeData(t.minute);
        t.second    = changeTimeData(t.second);
    }
    return t;
}


unsigned char getTimeData(int addr) {
    io_out8(0x0070, addr);
    return io_in8(0x0071);
}


unsigned char changeTimeData(char data) {
    return ((data & 0x0F) + ((data / 16) * 10));
}
