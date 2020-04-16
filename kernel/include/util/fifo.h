// ***************************************
//  include - util - fifo.h
//  Update  develop3.2
// ***************************************

#include <types.h>

#ifndef __FIFO__
#define __FIFO__

#define FIFO_BUFFER 64

void initFIFO(FIFO *fifo);
void putFIFO(FIFO *fifo, int low, int high);
nFIFO getFIFO(FIFO *fifo);

#endif  // __FIFO__
