/*********************************************
 * stdlib.h
 * ******************************************/

#include <types.h>

#ifndef __STDLIB__
#define __STDLIB__

void *malloc(unsigned int size);
void *calloc(unsigned int size, unsigned int len);
unsigned int free(void *addr, int size);

#endif  // __STDLIB__

