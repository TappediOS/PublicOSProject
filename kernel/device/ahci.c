/**********************************
 *  device - ahci.c
 *  Update  develop5.0
 *********************************/

#include <types.h>
#include <device/ahci.h>
#include <util/asmfunc.h>
extern HBA_MEMORY *hbaMemory;

#include <console/console.h>
#include <util/stdio.h>
extern Console console;


unsigned short pciReadByte(unsigned char bus, unsigned char device, unsigned char func, unsigned char offset) {
    unsigned int addr = ((unsigned int)(bus << 16) | (unsigned int)(device << 11)
                            | (unsigned int)(func << 8) | (unsigned int)(offset & 0xfc) | (unsigned int)(0x80000000));
    io_out32(PCI_CONFIG_ADDR, addr);
    return (unsigned short)((io_in32(PCI_CONFIG_DATA) >> ((offset %4) *8 )) &0xFFFF);
}

unsigned short pciReadWord(unsigned char bus, unsigned char device, unsigned char func, unsigned char offset) {
    unsigned int addr = ((unsigned int)(bus << 16) | (unsigned int)(device << 11)
                            | (unsigned int)(func << 8) | (unsigned int)(offset & 0xfc) | (unsigned int)(0x80000000));
    io_out32(PCI_CONFIG_ADDR, addr);
    return (unsigned short)((io_in32(PCI_CONFIG_DATA) >> ((offset &2) *8 )) &0xFFFF);
}

unsigned int pciReadDword(unsigned char bus, unsigned char device, unsigned char func, unsigned char offset) {
    unsigned int addr = ((unsigned int)(bus << 16) | (unsigned int)(device << 11)
                            | (unsigned int)(func << 8) | (unsigned int)(offset & 0xfc) | (unsigned int)(0x80000000));
    io_out32(PCI_CONFIG_ADDR, addr);
    return io_in32(PCI_CONFIG_DATA);
}

// sata(1.3.1) spec p8
PciDeviceInfo getPciInfo(int bus, int device, int func) {
    PciDeviceInfo pdInfo;
    if ((pdInfo.vendor = pciReadWord(bus, device, func, 0x00)) != 0xFFFF) {
        pdInfo.device       = pciReadWord(bus, device, func, 0x02);
        pdInfo.command      = pciReadWord(bus, device, func, 0x04);
        pdInfo.status       = pciReadWord(bus, device, func, 0x06);
        pdInfo.revisionId   = pciReadByte(bus, device, func, 0x08);
        pdInfo.progIf       = pciReadByte(bus, device, func, 0x09);
        pdInfo.subClass     = pciReadByte(bus, device, func, 0x0a);
        pdInfo.classCode    = pciReadByte(bus, device, func, 0x0b);
        pdInfo.cacheLineSize= pciReadByte(bus, device, func, 0x0c);
        pdInfo.latencyTimer = pciReadByte(bus, device, func, 0x0d);
        pdInfo.headerType   = pciReadByte(bus, device, func, 0x0e);
        pdInfo.bist         = pciReadByte(bus, device, func, 0x0f);
        pdInfo.capabilitiesPointer  = pciReadByte(bus, device, func, 0x34);
        pdInfo.interruptLine        = pciReadByte(bus, device, func, 0x3c);
        pdInfo.interruptPin = pciReadByte(bus, device, func, 0x3d);
    }
    return pdInfo;
}

void detectPciDevices(void) {
    int bus, device, func;
    char debug[128];
    unsigned int ret;
    PciDeviceInfo pdInfo;

    for (bus = 0; bus < 256; bus++) {
        for (device = 0; device < 32; device++) {
            for (func = 0; func < 8; func++) {
                pdInfo = getPciInfo(bus, device, func);
                if ((pdInfo.vendor != 0xFFFF)) {
                    sprintf(debug, "DETECT DEVICE [%x:%x:%x]", bus, device, func);
                    printConsole(&console, debug);
                    if (pdInfo.classCode == 0x01 && pdInfo.subClass == 0x06) {
                        hbaMemory = ((HBA_MEMORY *)(unsigned long long int)pciReadDword(bus, device, func, 0x24));
                        sprintf(debug, "DETECT SATA DEVICE : 0x%x",pciReadDword(bus, device, func, 0x24));
                        printConsole(&console, debug);
                    }
                }
            }
        }
    }
}

