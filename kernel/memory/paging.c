/******************************************
 *  paging.c
 *  update : develop4.0
 * ****************************************/

#include <types.h>
#include <memory/paging.h>
#include <util/asmfunc.h>

#include <console/console.h>
#include <util/stdio.h>
extern Console console;

void initPaging() {
    char debug[256];

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

    setCR3(0x2000);
    setCR4(getCR4() | 0x10);
}


