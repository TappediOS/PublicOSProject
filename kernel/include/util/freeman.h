/************************************
 *  freeman.h
 *  update  develop5.1
 ***********************************/

#ifndef __FREEMAN__
#define __FREEMAN__

/**  ver. int  **/
typedef struct nFREE {
    unsigned int start;
    unsigned int size;
} __attribute__((packed)) nFREE;

typedef struct FREE_MAN {
    nFREE *arr;
    unsigned int len;
} FREE_MAN;

void initFreeMan(FREE_MAN *freeMan, nFREE *head, unsigned int len, unsigned int start, unsigned int end);
unsigned int allocateFreeMan(FREE_MAN *freeMan, unsigned int size);

/**  ver. LLint  **/
typedef struct nFREEL
#endif  // __FREEMAN__

