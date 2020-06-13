/******************************************
 *  paging.c
 *  update : develop4.0
 * ****************************************/

#include <types.h>
#include <memory/paging.h>
#include <util/asmfunc.h>

static unsigned char page[MAX_HEAP_PAGES];

#include <console/console.h>
#include <util/stdio.h>
extern Console console;

void initPaging() {
    unsigned long long *pml4 = (unsigned long long *)0x2000;
    unsigned long long *pdpt = (unsigned long long *)0x3000;
    unsigned long long *pde  = (unsigned long long *)0x4000;
    unsigned int i;

    for (i = 0; i < 512; i++) {
        pml4[i] = 0x0000;
        pdpt[i] = 0x0000;
    }
    for (i = 0; i < 512 *6; i++) {
        pde[i] = 0x0000;
    }

    pml4[0] = (unsigned long long)0x3023;
    for (i = 0; i < 6; i++) {
        pdpt[i] = (unsigned long long)(0x1000 *i + 0x4023);
    }
    for (i = 0; i < 512 *6; i++) {
        pde[i] = 0x200000 * i + 0x83;
    }

    for (i = 0; i < MAX_HEAP_PAGES; i++)
        page[i] = 0;

    setCR3(0x2000);
    setCR4(getCR4() | 0x10);
}

void *allocatePage(void) {
    int n, bit;
    for (n = 0; n < MAX_HEAP_PAGES; n++) {
        for (bit = 0; bit < 8; bit++) {
            if ((page[n] & (1 << bit)) == 0) {
                page[n] |= (1 << bit);
                return (void *)((n *8 +bit) *0x200000 +(HEAP_START *1024 *1024));
            }
        }
    }
    return NULL;
}

void freePage(void *p) {
    unsigned int f = (p -(HEAP_START *1024 *1024));
    f /= 0x200000;
    unsigned char n = f /8;
    unsigned char bit = f %8;

    if (page[n] & (1 << bit))
        page[n] -= (1 << bit);
}


