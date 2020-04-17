// ************************************
//  device - mouse.c
//  Update  develop3.4
// ************************************

#include <types.h>
#include <graphic/graphic.h>
#include <device/mouse.h>

void initMouseInfo(MouseInfo *mi) {
    unsigned char i;
    for (i = 0; i < 3; i++)
        mi->data[i] = 0x00;
    mi->mx = gInfo->width / 2;
    mi->my = gInfo->height / 2;
    mi->step = 0;
}

void inputMouseInfo(MouseInfo *mi, char data) {
    mi->data[mi->step] = data;
    mi->step = (mi->step +1) % 3;
}

int decodeMouseInfo(MouseInfo *mi) {
    if (mi->step)
        return 0xFF;     // 3 byteが来ていない
    else {
        // decode
        mi->mx += mi->data[1];
        if (mi->mx < 0)
            mi->mx = 0;
        else if (mi->mx > gInfo->width -10)
            mi->mx = gInfo->width -10;

        mi->my += -mi->data[2];
        if (mi->my < 0)
            mi->my = 0;
        else if (mi->my > gInfo->height- 10)
            mi->my = gInfo->height - 10;
        return mi->data[0] & 0x07;
    }
}

void drawMouse(MouseInfo *mi) {
    unsigned int x, y;
    for (y = 0; y < 18; y++) {
        for (x = 0; x < 12; x++) {
            switch(cursor[y][x]) {
            case 0:
                break;
            case 1:
                drawPoint(mi->mx +x, mi->my +y, 0x000000);
                break;
            case 2:
                drawPoint(mi->mx +x, mi->my +y, 0xFFFFFF);
                break;
            }
        }
    }
}


