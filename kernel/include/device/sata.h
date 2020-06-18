/*****************************************
 *  sata.h
 *  update  develop5.0
 * **************************************/

#ifndef __DEVICE_SATA__
#define __DEVICE_SATA__

#define SATA_SIG_ATA        0x00000101
#define SATA_SIG_ATAPI      0xEB140101
#define SATA_SIG_SEMB       0xC33C0101
#define SATA_SIG_PM         0x96690101

#define HBA_PORT_IPM_ACTIVE     1
#define HBA_PORT_DET_PRESENT    3

#define READ_DMA_EXT        0x25
#define WRITE_DMA_EXT       0x35

void initSata(void);
int findFreeCmdSlot(HBA_PORT *hbaPort);
void buildCmdTbl(HBA_CMD_PARAMS *hbaCmdParams);
void buildCmd(HBA_PORT *hbaPort, HBA_CMD_PARAMS *hbaCmdParams);
void startSataCmd(HBA_PORT *hbaPort);
void stopSataCmd(HBA_PORT *hbaPort);
void sataRead(HBA_PORT *hbaPort, unsigned int portno, unsigned long long start, unsigned short cnt, unsigned char *buf);
void sataWrite(HBA_PORT *hbaPort, unsigned int portno, unsigned long long start, unsigned short cnt, unsigned char *buf);
void checkSataPort(void);

#endif  // __DEVICE_SATA__
