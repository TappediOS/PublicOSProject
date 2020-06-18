// **************************************
//  include - types.h
//  Update  develop3.4
// **************************************

#ifndef __TYPES__
#define __TYPES__

#define NULL    0

// console
#define CONSOLE_ROW     80
#define CONSOLE_LINE    32

typedef struct Console {
    char buf[CONSOLE_ROW * CONSOLE_LINE];
    unsigned int ptr;
} Console;


// device - mouse
typedef struct MouseInfo {
    short int mx, my;
    char data[3];
    char step;
} MouseInfo;

// device - pci
typedef struct PciDeviceInfo {
    unsigned short vendor;
    unsigned short device;
    unsigned short command;
    unsigned short status;
    unsigned char  revisionId;
    unsigned char  progIf;
    unsigned char  subClass;
    unsigned char  classCode;
    unsigned char  cacheLineSize;
    unsigned char  latencyTimer;
    unsigned char  headerType;
    unsigned char  bist;
    unsigned char  capabilitiesPointer;
    unsigned char  interruptLine;
    unsigned char  interruptPin;
} PciDeviceInfo;

// device - sata

typedef struct DMA_SETUP_FIS {
    unsigned char fisType;
    unsigned char portMultiplier:4;
    unsigned char reserve0:1;
    unsigned char dataTransferDirection:1;      // 1 - device2host
    unsigned char interruptBit:1;
    unsigned char autoActivate:1;
    unsigned char reserved1[2];
    unsigned long long int dmaBufferId;
    unsigned int reserved2;
    unsigned int dmaBufferOffset;
    unsigned int transferCount;
    unsigned int reserved3;
} __attribute__((packed)) DMA_SETUP_FIS;

typedef struct PIO_SETUP_FIS {
    // DWORD 0
    unsigned char fisType;
    unsigned char portMultiplier:4;
    unsigned char reserved0:1;
    unsigned char dataTransfer:1;
    unsigned char interruptBit:1;
    unsigned char reserved1:1;
    unsigned char status;
    unsigned char error;

    // DWORD 1
    unsigned char lba0;
    unsigned char lba1;
    unsigned char lba2;
    unsigned char device;

    // DWORD 2
    unsigned char lba3;
    unsigned char lba4;
    unsigned char lba5;
    unsigned char reserve2;

    // DWORD 3
    unsigned short int count;
    unsigned char reserve3;
    unsigned char eStatus;

    // DWORD 4
    unsigned short int transferCount;
    unsigned char reserve4[2];
} __attribute__((packed)) PIO_SETUP_FIS;

typedef struct D2H_REG_FIS {
    // DWORD 0
    unsigned char fisType;
    unsigned char portMultiplier:4;
    unsigned char reserved0:2;
    unsigned char interruptBit:1;
    unsigned char reserved1:1;
    unsigned char status;
    unsigned char error;

    // DWORD 1
    unsigned char lba0;
    unsigned char lba1;
    unsigned char lba2;
    unsigned char device;

    // DWORD 2
    unsigned char lba3;
    unsigned char lba4;
    unsigned char lba5;
    unsigned char reserve2;

    // DWORD 3
    unsigned short int count;
    unsigned short int reserve3;

    // DWORD 4
    unsigned char reserve4[4];
} __attribute__((packed)) D2H_REG_FIS;

typedef struct H2D_REG_FIS {
    unsigned char fisType;
    unsigned char portMultiplier:4;
    unsigned char reserve0:3;
    unsigned char cmd_ctrl:1;
    unsigned char cmd;
    unsigned char featurel;

    // DWORD 1
    unsigned char lba0;
    unsigned char lba1;
    unsigned char lba2;
    unsigned char device;

    // DWORD 2
    unsigned char lba3;
    unsigned char lba4;
    unsigned char lba5;
    unsigned char featureh;

    // DWORD 3
    unsigned short int cnt;
    unsigned char isoCmdComp;
    unsigned char control;

    // DWORD 4
    unsigned char reserve1[4];
} __attribute__((packed)) H2D_REG_FIS;

typedef struct HBA_FIS {
    DMA_SETUP_FIS   dmaSetupFis;
    char reserve0[0x20 - 0x1C];
    PIO_SETUP_FIS   pioSetupFis;
    char reserve1[0x40 - 0x34];
    D2H_REG_FIS     d2hRegFis;
    char reserve2[0x58 - 0x54];
    unsigned char setDeviceBitsFis[0x60 - 0x58];
    char unknownFis[0xA0 - 0x60];
    char reserve3[0x100 - 0xA0];
} HBA_FIS;

typedef struct HBA_CMD_HEADER {
    unsigned char cmdFisLength:5;
    unsigned char atapi:1;
    unsigned char write:1;      // 1: h2d   0: d2h
    unsigned char prefetchable:1;
    unsigned char reset:1;
    unsigned char bist:1;
    unsigned char clear:1;
    unsigned char reserve0:1;
    unsigned char portMultiplierPort:4;

    unsigned short int physRegionDescTableLength;
    volatile unsigned int physRegionDescByteCntTransferred;

    // DW2, 3
    unsigned long long int cmdTableDescBaseAddr;

    // DW4-7
    unsigned int reserve1[4];
} __attribute__((packed)) HBA_CMD_HEADER;

typedef struct HBA_PRDT_ENTRY {
    unsigned long long int dbAddr;
    unsigned int reserve;
    unsigned int byteCnt:22;
    unsigned int reserve1:9;
    unsigned int interruptCompletion:1;
} __attribute__((packed)) HBA_PRDT_ENTRY;

typedef struct HBA_CMD_TBL {
    unsigned char cmdFis[0x40];
    unsigned char acmd[0x50 - 0x40];
    unsigned char reserved[0x80 - 0x50];
    HBA_PRDT_ENTRY prdtEntry[65536];
} __attribute__((packed)) HBA_CMD_TBL;

typedef struct HBA_CMD_LST {
    HBA_CMD_HEADER hbaCmdHeader[32];
} HBA_CMD_LST;

typedef struct HBA_PORT {
    unsigned long long cmdListBaseAddr;
    unsigned long long fisBaseAddr;
    unsigned int interruptStat;
    unsigned int interruptEnable;
    unsigned int cmd;
    unsigned int reserve0;
    unsigned int taskFileData;
    unsigned int signature;
    unsigned int sataStatus;
    unsigned int sataControl;
    unsigned int sataError;
    unsigned int sataActive;
    unsigned int cmdIssue;
    unsigned int sataNotification;
    unsigned int fisBasedSwitchControl;
    unsigned int reserve1[11];
    unsigned int vendor[4];
} __attribute__((packed)) HBA_PORT;

typedef struct HBA_MEMORY {
    unsigned int hostCapability;
    unsigned int globalHostControl;
    unsigned int interruptStat;
    unsigned int portImplemented;
    unsigned int version;
    unsigned int cmdCompletionCoalescingControl;
    unsigned int cmdCompletionCoalescingPorts;
    unsigned int enclosureManagementLocation;
    unsigned int enclosureManagementControl;
    unsigned int hostCapabilitiesExtended;
    unsigned int bios_osHandoffControl_Status;
    unsigned char reserve[0xa0 - 0x2c];
    unsigned char vendor[0x100 - 0xa0];
    HBA_PORT ports[32];
} HBA_MEMORY;

typedef struct HBA_CMD_PARAMS {
    unsigned char fisType;
    unsigned char cmdType;
    unsigned char cfisLen;
    unsigned long long *cmdTblBaseAddr;
    unsigned long long *logicalBlockAddr;
    unsigned short int cnt;
    unsigned long long *dbAddr;
    unsigned char w;
} __attribute__((packed)) HBA_CMD_PARAMS;

// graphics
typedef struct GraphicInfo {
    unsigned long *vram;
    unsigned short int width;
    unsigned short int height;
} GraphicInfo;


// gdtidt
typedef unsigned long long SEGMENT_DESCRIPTOR;

typedef struct GATE_DESCRIPTOR {
    unsigned short offset_00_15;
    unsigned short selector;
    unsigned short ist      : 3;
    unsigned short _zero1   : 5;
    unsigned short type     : 4;
    unsigned short _zero2   : 1;
    unsigned short dpl      : 2;
    unsigned short p        : 1;
    unsigned short offset_31_16;
    unsigned int   offset_63_32;
    unsigned int   _reserved;
} GATE_DESCRIPTOR;

// time
typedef struct Time {
    unsigned int year;
    unsigned char month;
    unsigned char day;
    unsigned char week;
    unsigned char hour;
    unsigned char minute;
    unsigned char second;
} Time;

// util/fifo.c
typedef struct nFIFO {
    int low;
    int high;
} nFIFO;

typedef struct FIFO {
    nFIFO nfifo[64];
    unsigned char read;
    unsigned char write;
} FIFO;

#endif  // __TYPES__
