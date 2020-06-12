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

void initPaging(void);
extern void setPaging(void);

#endif  // __INCLUDE_PAGING__

