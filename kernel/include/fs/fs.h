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

typedef struct FILE_INFO {
    unsigned char stat;
    char filename[24];
    unsigned int  startSector;
    unsigned int  numOfSector;
    unsigned char lastSectorSize;
} FILE_INFO;


typedef struct DIR_INFO {
    unsigned int upDirSector;
    unsigned int nextDirSector;
    unsigned int numOfFile;
    FILE_INFO    *fileInfo;
} DIR_INFO;

unsigned long long getSector2Num(int start, unsigned int size);
void loadHddFree(void);
unsigned int openDir(char *fName, DIR_INFO *dirInfo);





#endif  // __FS__

