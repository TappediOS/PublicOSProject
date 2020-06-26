/*************************************
 *  fs.h
 *  update  develop5.1
 * **********************************/

#include <types.h>

#ifndef __FS__
#define __FS__

#define SECTOR      0x200

// sector
#define HDD_INFO    0
#define HDD_FREE_INFO_START     1
#define HDD_FREE_INFO_END       5
#define ROOT_DIR_SECTOR         (HDD_FREE_INFO_END +1)
#define HDD_SIZE                32768

typedef struct HDD_FREE {
    unsigned long long sector;
    unsigned long long size;        // sector 0x200
} __attribute__((packed)) HDD_FREE;

unsigned long long getSector2LLNum(int start);
void loadHddFree(void);
void setHddFree(void);
unsigned long long getFreeSector(unsigned long long int size);
void showFreeRegion(void);





#endif  // __FS__

