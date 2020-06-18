/********************************
 *  include - device - ahci.h
 *  update  develop5.0
 *  ****************************/

#ifndef __DEVICE_AHCI__
#define __DEVICE_AHCI__

#define PCI_CONFIG_ADDR     0x0cf8
#define PCI_CONFIG_DATA     0x0cfc

unsigned short pciReadByte(unsigned char bus, unsigned char device, unsigned char func, unsigned char offset);
unsigned short pciReadWord(unsigned char bus, unsigned char device, unsigned char func, unsigned char offset);
unsigned int   pciReadDword(unsigned char bus, unsigned char device, unsigned char func, unsigned char offset);
PciDeviceInfo getPciInfo(int bus, int device, int func);
void detectPciDevices(void);


#endif  // __DEVICE_AHCI__

