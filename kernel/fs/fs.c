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
static unsigned char secBuf[0x200];

extern HBA_MEMORY *hbaMemory;


#include <util/stdio.h>
#include <console/console.h>
extern Console console;
char debug[256];

unsigned long long getSector2LLNum(int start) {
    unsigned int i;
    unsigned long long ret = 0;
    for (i = 0; i < 8; i++) {
        ret <<= 8;
        ret += secBuf[start +i];
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
            setMemoryManagement(&hddMan, getSector2LLNum(i *16),
                    getSector2LLNum(i *16 +8), (sector-1) *32 +i);
        }
    }
    printConsole(&console, "[success] Load Hdd Free Region");
}




