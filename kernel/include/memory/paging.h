/*****************************************
 *  paging.h
 *  Update develop 4.0
 *  **************************************/

#include <types.h>

#ifndef __INCLUDE_PAGING__
#define __INCLUDE_PAGING__

#define PML4E   0x2000
#define PDPTE   0x3000
#define PDE     0x4000

#define HEAP_START      1024        // MB
#define MEMORY_SIZE     6144        // MB
#define MAX_HEAP_PAGES  ((MEMORY_SIZE - HEAP_START) /(2*8))

void initPaging(void);
void *allocatePage(void);
void freePage(void *page);

#endif  // __INCLUDE_PAGING__

