// ************************************
//  device - keyboard.c
//  Update  develop4.0
// ************************************

#include <types.h>

#include <device/keyboard.h>
#include <util/fifo.h>

extern KeyboardInfo kbdInfo;

// 0x0E = BS
// 0x0F = TAB
// 0x1C = ENTER
// 0x1D = CTRL(L)
//

static char key1[] = {
//  00   01   02   03   04   05   06   07   08   09   0A   0B   0C   0D   0E   0F
    '.', '.', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', ';', '.', '.',
    'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '.', '.', 'a', 's',
    'd', 'f', 'g', 'h', 'j', 'k', 'l', ':', '^', '.', '.', '@', 'z', 'x', 'c', 'v',
    'b', 'n', 'm', ',', '.', '/', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' };

void initKbdInfo(KeyboardInfo *kbdInfo) {
    initFIFO(&(kbdInfo->kbdFIFO));
}

enum KeyCode decodeKbdInfo(KeyboardInfo *kbdInfo) {
    enum KeyCode ret = KEY_NULL;
    nFIFO data = getFIFO(&(kbdInfo->kbdFIFO));
    if (data.high == 0) return ret;
    else if (data.high == 0x01) {
        ret = keyDecode(data.low);
        return ret;
    }
}

enum KeyCode keyDecode(unsigned char data) {
    enum KeyCode key = KEY_NULL;
    if (data < 0x80) {
        return data;
    }
    return key;
}


unsigned char getKey(enum KeyCode key) {
    return key1[key];
}

