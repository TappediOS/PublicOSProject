/********************************************
 *  fs.c
 *  update  develop5.1
 *******************************************/

#include <types.h>
#include <device/sata.h>
#include <fs/fs.h>
#include <util/memman.h>
#include <util/string.h>

static nMEM_MAN nHddMan[(HDD_FREE_INFO_END - HDD_FREE_INFO_START) *SECTOR /0x10];
static MEM_MAN  hddMan;
static unsigned short int secBufIndex;
static unsigned char secBuf[0x200];

extern HBA_MEMORY *hbaMemory;


#include <util/stdio.h>
#include <console/console.h>
extern Console console;
char debug[256];

unsigned long long getSector2Num(int start, unsigned int size) {
    unsigned int i;
    unsigned long long ret = 0;
    for (i = 0; i < size; i++) {
        ret <<= 8;
        ret += secBuf[start +i];
        secBufIndex++;
    }
    return ret;
}


void loadHddFree(void) {
    unsigned int sector, i;
    initMemoryManagement(&hddMan,
            (HDD_FREE_INFO_END -HDD_FREE_INFO_START) *SECTOR /0x10, nHddMan, HDD_SIZE);

    sataRead(hbaMemory->ports, 0, 0, 1, (unsigned char *)secBuf);
    if (strncmp((char *)secBuf, "_MINDOWS FORMAT_", 0x0F) != 0) {
        printConsole(&console, "Format Error");
        return;
    }

    sector = HDD_FREE_INFO_START;
    for (sector = HDD_FREE_INFO_START; sector < HDD_FREE_INFO_END; sector++) {
        sataRead(hbaMemory->ports, 0, sector, 1, secBuf);
        for (i = 0; i < 32; i++) {
            setMemoryManagement(&hddMan, getSector2Num(i *16, 8),
                    getSector2Num(i *16 +8, 8), (sector-1) *32 +i);
        }
    }
    printConsole(&console, "[success] Load Hdd Free Region");
}

unsigned int openDir(char *fName, DIR_INFO *dirInfo) {
    if (strcmp(fName, "root") == 0) {
        sataRead(hbaMemory->ports, 0, ROOT_DIR_SECTOR, 1, secBuf);
        secBufIndex = 0;

        dirInfo->upDirSector    = getSector2Num(0x04, 4);
        dirInfo->nextDirSector  = getSector2Num(0x08, 4);
        dirInfo->numOfFile      = getSector2Num(0x0c, 4);
        if (dirInfo->numOfFile) {
            dirInfo->fileInfo = (FILE_INFO *)calloc(sizeof(FILE_INFO), dirInfo->numOfFile);
            if (dirInfo->fileInfo == 0x00) {
                return 0x03;        // memory error
            }
            unsigned int index, len;
            secBufIndex = 0x20;
            for (index = 0; index < dirInfo->numOfFile; index++) {
                dirInfo->fileInfo[index].stat = (unsigned char)getSector2Num(secBufIndex, 1);
                memset(dirInfo->fileInfo[index].filename, 0, 24);
                for (len = 0; len < 22; len++)
                    dirInfo->fileInfo[index].filename[len] = (char)getSector2Num(secBufIndex, 1);
                dirInfo->fileInfo[index].startSector = (unsigned int)getSector2Num(secBufIndex, 4);
                dirInfo->fileInfo[index].numOfSector = (unsigned int)getSector2Num(secBufIndex, 3);
                dirInfo->fileInfo[index].lastSectorSize = (unsigned char)getSector2Num(secBufIndex, 2);
            }
        }
        return 0;
    }
    FILE_INFO *fileInfo = dirInfo->fileInfo;
    if (fileInfo == 0x00) {
        return 0x01;        // dir is empty
    }
    unsigned int index = 0;
    for (index = 0; index < dirInfo->numOfFile; index++) {
        if (strcmp(fileInfo[index].filename, fName) == 0) {
            // put dirInfo
                return 0;
        }
    }
    return 0x02;        // dir is not found
}


