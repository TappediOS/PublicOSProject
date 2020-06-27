/********************************************
 *  stdlib.c
 *  update  develop5.2
 * *****************************************/

#include <types.h>
#include <util/stdlib.h>
#include <util/memman.h>

extern MEM_MAN kernelMemMan;

#include <util/stdio.h>
#include <console/console.h>
extern char debug[256];
extern Console console;


void *malloc(unsigned int size) {
    void *addr;
    addr = (void *)allocateMemoryManagement(&kernelMemMan, size);
    return (unsigned int *)(addr + 0x30000000);
}

void *calloc(unsigned int size, unsigned int len) {
    void *addr;
    addr = (void *)allocateMemoryManagement(&kernelMemMan, size * len);
    return (void *)(addr + 0x30000000);
}

unsigned int free(void* addr, int size) {
    unsigned int a = (unsigned int)(addr - 0x30000000);
    return freeMemoryManagement(&kernelMemMan, a, size);
}
