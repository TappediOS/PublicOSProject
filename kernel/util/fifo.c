// **************************************
//  util - fifo.c
//  Update  develop3.2
// **************************************

#include <types.h>
#include <util/fifo.h>

void initFIFO(FIFO *fifo) {
    unsigned int i;
    for (i = 0; i < FIFO_BUFFER; i++) {
        fifo->nfifo[i].low  = 0;
        fifo->nfifo[i].high = 0;
    }
    fifo->read  = 0;
    fifo->write = 0;
}

void putFIFO(FIFO *fifo, int low, int high) {
    fifo->write = (fifo->write + 1) % FIFO_BUFFER;
    fifo->nfifo[fifo->write].low   = low;
    fifo->nfifo[fifo->write].high  = high;
}

nFIFO getFIFO(FIFO *fifo) {
    nFIFO f = {0, 0};
    if (fifo->read == fifo->write)
        return f;
    else {
        fifo->read = (fifo->read + 1) % FIFO_BUFFER;
        return fifo->nfifo[fifo->read];
    }
}
