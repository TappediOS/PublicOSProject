/*******************************************
 *  device - sata.c
 *  Update  develop5.0
 ******************************************/

#include <types.h>
#include <device/sata.h>
#include <util/asmfunc.h>
#include <util/string.h>

extern HBA_MEMORY *hbaMemory;

static HBA_FIS     hbaFis[32];
static HBA_CMD_LST hbaCmdLst[32];
static HBA_CMD_TBL hbaCmdTbl;

#include <console/console.h>
#include <util/stdio.h>
extern Console console;

static char debug[0x200];

// sata(1.3.1) spec p103
void initSata(void) {
    int i;
    char debug[256];

    hbaMemory->globalHostControl = 0x80000000;      // GHC.AE = 1
    hbaMemory->globalHostControl |= 0x00000001;     // GHC.HR = 1
    while (hbaMemory->globalHostControl & 0x01) {
        sprintf(debug, ".");
        printConsole(&console, debug);
    }

    sprintf(debug, "[success] HBA reset");
    printConsole(&console, debug);

    hbaMemory->globalHostControl |= 0x80000000;

    unsigned int pi = hbaMemory->portImplemented;
    unsigned int pidle = 0;
    for (i = 0; i < 32; i++) {
        if (pi >> i) {
            if ((hbaMemory->ports[i].cmd & 0x811) == 0) {
                pidle |= (1 << i);
            }
            else {
                sprintf(debug, "port is busy - P%dCMD : 0x%x", i, hbaMemory->ports[i].cmd);
                printConsole(&console, debug);
            }
        }
    }
    sprintf(debug, "[success] PIDLE");
    printConsole(&console, debug);

    pi = hbaMemory->portImplemented;
    while (pi != pidle) {
        io_hlt();
    }

    hbaMemory->ports[0].cmdListBaseAddr = (unsigned long long int)(&hbaCmdLst[0]);
    hbaMemory->ports[0].fisBaseAddr = (unsigned long long int)(&hbaFis[0]);
    hbaMemory->ports[0].cmd |= 0x10;

    hbaMemory->ports[0].sataError |= 0x7ff0f03;
    while (hbaMemory->ports[0].sataError) {
        io_hlt();
    }

    hbaMemory->ports[0].interruptStat = 0xFFFFFFFF;
    while (hbaMemory->ports[0].interruptStat) {
        io_hlt();
    }

    hbaMemory->interruptStat = 0x00000000;
    while (hbaMemory->interruptStat) {
        io_hlt();
    }

    hbaMemory->ports[0].interruptEnable = 0xfdc000ff;
    hbaMemory->globalHostControl |= 0x02;

}

/**********************************************************************
 *      HBA util function
 *********************************************************************/

int findFreeCmdSlot(HBA_PORT *hbaPort) {
    unsigned int i, slots = (hbaPort->cmdIssue | hbaPort->sataActive);
    for (i = 0; i < 32; i++) {
        if ((slots & 1) == 0) {
            return i;
        }
        slots >>= 1;
    }
    return -1;
}

void buildCmdTbl(HBA_CMD_PARAMS *hbaCmdParams) {
    memset(&hbaCmdTbl, 0, sizeof(hbaCmdTbl));

    H2D_REG_FIS *h2dRegFis;
    if (hbaCmdParams->fisType == 0x27) {
        h2dRegFis = (H2D_REG_FIS *)(&hbaCmdTbl);
        h2dRegFis->fisType = 0x27;
        h2dRegFis->cmd_ctrl = 1;
        h2dRegFis->cmd = hbaCmdParams->cmdType;
        h2dRegFis->device = (1 << 6);
        h2dRegFis->lba0 = (unsigned char)(((unsigned long long)(hbaCmdParams->logicalBlockAddr) >>  0) & 0xff);
        h2dRegFis->lba1 = (unsigned char)(((unsigned long long)(hbaCmdParams->logicalBlockAddr) >>  8) & 0xff);
        h2dRegFis->lba2 = (unsigned char)(((unsigned long long)(hbaCmdParams->logicalBlockAddr) >> 16) & 0xff);
        h2dRegFis->lba3 = (unsigned char)(((unsigned long long)(hbaCmdParams->logicalBlockAddr) >> 24) & 0xff);
        h2dRegFis->lba4 = (unsigned char)(((unsigned long long)(hbaCmdParams->logicalBlockAddr) >> 32) & 0xff);
        h2dRegFis->lba5 = (unsigned char)(((unsigned long long)(hbaCmdParams->logicalBlockAddr) >> 40) & 0xff);
        h2dRegFis->cnt  = hbaCmdParams->cnt;
    }
    // printConsole(&console, "SET h2dRegFis");

    unsigned int i;
    unsigned short cnt = hbaCmdParams->cnt;
    unsigned int prdtl = (int)((hbaCmdParams->cnt -1) >>4) + 1;
    unsigned char *buf = (unsigned char *)hbaCmdParams->dbAddr;
    for (i = 0; i < prdtl -1; i++) {
        hbaCmdTbl.prdtEntry[i].dbAddr   = (unsigned long long int)buf;
        hbaCmdTbl.prdtEntry[i].byteCnt  = 8 *1024 -1;
        hbaCmdTbl.prdtEntry[i].interruptCompletion = 1;
        buf += 8 *1024;
        cnt -= 16;
    }
    // printConsole(&console, "READ OR WRITE");

    hbaCmdTbl.prdtEntry[i].dbAddr   = (unsigned long long int)buf;
    hbaCmdTbl.prdtEntry[i].byteCnt  = (cnt <<9) -1;
    hbaCmdTbl.prdtEntry[i].interruptCompletion = 1;
}

void buildCmdHeader(HBA_PORT *port, unsigned int slot, HBA_CMD_PARAMS *hbaCmdParams) {
    HBA_CMD_HEADER *hbaCmdHeader = ((HBA_CMD_HEADER *)port->cmdListBaseAddr +slot);
    memset(hbaCmdHeader, 0, 0x400);
    hbaCmdHeader->cmdTableDescBaseAddr = (unsigned long long)&hbaCmdTbl;
    hbaCmdHeader->physRegionDescTableLength = (unsigned short)(((hbaCmdParams->cnt -1) >>4) +1);
    hbaCmdHeader->cmdFisLength = hbaCmdParams->cfisLen;
    hbaCmdHeader->write = hbaCmdParams->w;
    // printConsole(&console, "BUILD CMD HEADER");
}


void buildCmd(HBA_PORT *hbaPort, HBA_CMD_PARAMS *hbaCmdParams) {
    int slot = findFreeCmdSlot(hbaPort);
    buildCmdTbl(hbaCmdParams);
    buildCmdHeader(hbaPort, slot, hbaCmdParams);
    hbaPort->cmdIssue |= (1 << slot);
    // printConsole(&console, "[success] BUILD CMD");
}

/**********************************************************************
 *      HBA command function
 *********************************************************************/
void startSataCmd(HBA_PORT *hbaPort) {
    hbaPort->cmd &= 0xfffffffe;
    while (hbaPort->cmd & 0x8000) io_hlt();
    hbaPort->cmd |= 0x10;
    hbaPort->cmd |= 0x01;
    // printConsole(&console, "start Sata Cmd");
}

void stopSataCmd(HBA_PORT *hbaPort) {
    hbaPort->cmd &= ~0x01;
    while ((hbaPort->cmd & 0x4000) || (hbaPort->cmd & 0x8000))
        io_hlt();
    hbaPort->cmd &= ~0x10;
    // printConsole(&console, "stop Stat Cmd");
}

void sataRead(HBA_PORT *hbaPort, unsigned int portno, unsigned long long start, unsigned short cnt, unsigned char *buf) {
    HBA_CMD_PARAMS hbaCmdParams;
    hbaCmdParams.fisType = 0x27;
    hbaCmdParams.cmdType = READ_DMA_EXT;
    hbaCmdParams.cfisLen = 0x05;
    hbaCmdParams.logicalBlockAddr = (unsigned long long *)start;
    hbaCmdParams.cnt = cnt;
    hbaCmdParams.dbAddr = (unsigned long long *)buf;
    hbaCmdParams.w = 0;

    // printConsole(&console, "----------  START READING FROM SATA DRIVE  ----------");
    startSataCmd(hbaPort);
    // printConsole(&console, "[success] start Sata Cmd");
    buildCmd(hbaPort, &hbaCmdParams);
    // printConsole(&console, "[success] build Cmd");
    while (hbaPort->interruptStat == 0) {
        // io_hlt();
    }
    // printConsole(&console, "[success] wait interrupt");
    hbaPort->interruptStat |= hbaPort->interruptStat;
    while (hbaPort->interruptStat) {
        // io_hlt();
    }
    // printConsole(&console, "[success] clear pxis");
    hbaMemory->interruptStat |= (1 << portno);
    while (hbaMemory->interruptStat) {
        // io_hlt();
    }
    // printConsole(&console, "[success] clear ghc interrupt");
    while (hbaPort->cmdIssue) {
        // io_hlt();
    }
    // printConsole(&console, "[success] wait pxci clear");
    // printConsole(&console, "----------  FINISH READING FROM SATA DRIVE  ----------");
}

void sataWrite(HBA_PORT *hbaPort, unsigned int portno, unsigned long long start, unsigned short cnt, unsigned char *buf) {
    HBA_CMD_PARAMS hbaCmdParams;
    hbaCmdParams.fisType = 0x27;
    hbaCmdParams.cmdType = WRITE_DMA_EXT;
    hbaCmdParams.cfisLen = 0x05;
    hbaCmdParams.logicalBlockAddr = (unsigned long long *)start;
    hbaCmdParams.cnt = cnt;
    hbaCmdParams.dbAddr = (unsigned long long *)buf;
    hbaCmdParams.w = 1;

    // printConsole(&console, "----------  START WRITING TO SATA DRIVE  ----------");
    startSataCmd(hbaPort);
    // printConsole(&console, "[success] start Sata Cmd");
    buildCmd(hbaPort, &hbaCmdParams);
    // printConsole(&console, "[success] build Cmd");
    // wait interrupt
    while (hbaPort->interruptStat == 0) {
        sprintf(debug, "HBA.IS : 0x%x", hbaPort->interruptStat);
        printConsole(&console, debug);
        // io_hlt();
    }
    // printConsole(&console, "[success] wait interrupt");
    // clear pxis
    hbaPort->interruptStat |= hbaPort->interruptStat;
        printConsole(&console, "step2");
    while (hbaPort->interruptStat) {
        // io_hlt();
    }
    // printConsole(&console, "[success] clear pxis");
    // clear ghc interrupt
    hbaMemory->interruptStat |= (1 << portno);
    while (hbaMemory->interruptStat) {
        printConsole(&console, "step3");
        // io_hlt();
    }
    // printConsole(&console, "[success] clear ghc interrupt");
    // wait pxci clear
    while (hbaPort->cmdIssue) {
        // io_hlt();
    }
    // printConsole(&console, "[success] wait pxci clear");
    // printConsole(&console, "----------  FINISH WRITING TO SATA DRIVE  ----------");
}

void checkSataPort(void) {
    int i;
    unsigned int pi = hbaMemory->portImplemented;
    unsigned int ssts, sig;

    sprintf(debug, "sizeof HBA_MEMORY : 0x%x", sizeof(HBA_MEMORY));
    printConsole(&console, debug);

    sprintf(debug, "Major Version : 0x%x", hbaMemory->version);
    printConsole(&console, debug);

    initSata();
    sprintf(debug, "[success] initialization sata port");
    printConsole(&console, debug);

    // sataWrite(hbaMemory->ports, 0, 0x00, 1, (unsigned char *)debug);
    // sataRead(hbaMemory->ports, 0, 0x00, 1, (unsigned char *)debug);
}
