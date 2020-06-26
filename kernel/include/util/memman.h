/***********************************
 *  memman.h
 *  update  develop5.1
 **********************************/

#include <types.h>

#ifndef __MEMMAN__
#define __MEMMAN__

/**  uint32  **/
typedef struct {
    unsigned int start;
    unsigned int end;
} __attribute__((packed)) nMEM_MAN;

typedef struct {
    nMEM_MAN *mem;
    unsigned int len;       // nMEM_MANのサイズ
    unsigned int size;      // 管理するサイズ
} __attribute__((packed)) MEM_MAN;


void initMemoryManagement(
        MEM_MAN *memMan, unsigned int memManSize,
        nMEM_MAN *head, unsigned int manSize     );
void setMemoryManagement(MEM_MAN *memMan, unsigned int start, unsigned int end, unsigned int index);
unsigned int allocateMemoryManagement(MEM_MAN *memMan, unsigned int size);
unsigned int freeMemoryManagement(MEM_MAN *memMan, unsigned int start, unsigned int size);
void showMemoryManagement(MEM_MAN *memMan);



#endif  // __MEMMAN__

