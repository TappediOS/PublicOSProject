/**********************************************
 *  memman.c
 *  update  develop5.1
 *********************************************/

#include <types.h>
#include <util/memman.h>

#include <util/stdio.h>
#include <console/console.h>
extern Console console;
extern char debug[256];

// argument :   memMan      : メモリ管理領域のアドレス
//              memManSize  : メモリ管理領域の大きさ
//              head        : メモリ管理ノードの先頭アドレス
//              manSize     : 管理するメモリ領域のサイズ
//
//  head
//  -----------------------------------------------------
//  | 0 |        |   1    |                             |
//  |   |        |        |                             |
//  -----------------------------------------------------
//  <-------------------  memManSize  ------------------>

void initMemoryManagement(
        MEM_MAN *memMan, unsigned int len,
        nMEM_MAN *head, unsigned int manSize     ) {

    memMan->len = len;
    memMan->size = manSize;
    memMan->mem = head;

    unsigned int i;
    for (i = 0; i < memMan->len; i++) {
        memMan->mem[i].start = 0x00;
        memMan->mem[i].end   = 0x00;
    }

    memMan->mem[1].start = manSize;
}

void setMemoryManagement(MEM_MAN *memMan, unsigned int start, unsigned int end, unsigned int index) {
    memMan->mem[index].start = start;
    memMan->mem[index].end   = end;
}

unsigned int allocateMemoryManagement(MEM_MAN *memMan, unsigned int size) {
    unsigned int i, ret = 0;
    for (i = 0; i < memMan->len -1; i++) {
        if (memMan->mem[i+1].start - memMan->mem[i].end > size) {
            ret = memMan->mem[i].end;
            memMan->mem[i].end += size;
            return ret;
        }
    }
    return ret;
}

unsigned int freeMemoryManagement(MEM_MAN *memMan, unsigned int start, unsigned int size) {
    unsigned int end = start + size;
    unsigned int ret = 0;
    unsigned int index = 0, x;

    while (memMan->mem[index].start > start)
        index++;

    if (memMan->mem[index].end < start)
        return ret;         // 既に解放してある領域

    if (memMan->mem[index].end < end)
        return ret;         // 一部解放してある領域

    // 領域を丸々解放
    if (memMan->mem[index].start == start && memMan->mem[index].end == end) {
        for (x = index; x < memMan->len -1; x++) {
            memMan->mem[x] = memMan->mem[x+1];
        }
    }
    // 開始がかぶってる
    else if (memMan->mem[index].start == start) {
        memMan->mem[index].start += size;
    }
    // 終了地点がかぶってる
    else if (memMan->mem[index].end == end) {
        memMan->mem[index].end -= size;
    }
    else {
        if (memMan->mem[memMan->len -1].start == memMan->size) {
            return ret;     // これ以上広げられない
        }
        for (x = memMan->len-1; x > index; x--) {
            memMan->mem[x] = memMan->mem[x-1];
        }
        memMan->mem[index].end = start;
        memMan->mem[index+1].start = end;
    }
    return size;
}

void showMemoryManagement(MEM_MAN *memMan) {
    sprintf(debug, "------------------  memMan  ------------------");
    printConsole(&console, debug);

    sprintf(debug, "LEN : 0x%08x   SIZE : 0x%08x", memMan->len, memMan->size);
    printConsole(&console, debug);

    unsigned int index = 0;
    // do {
    for (index = 0; index < 10; index++) {
        sprintf(debug, " 0x%08x  0x%08x", memMan->mem[index].start, memMan->mem[index].end);
        printConsole(&console, debug);
        // index++;
    } // while (memMan->mem[index].start != memMan->size);

    sprintf(debug, "----------------------------------------------");
    printConsole(&console, debug);
}

