// global.h
// update  ver.develop0.1

#include <IOStruct.h>
#include <SystemStruct.h>

#ifndef __GLOBAL__
#define __GLOBAL__

EFI_SYSTEM_TABLE        *gST = NULL;
EFI_BOOT_SERVICES       *gBS = NULL;
EFI_RUNTIME_SERVICES    *gRS = NULL;

EFI_STATUS initGlobal(EFI_SYSTEM_TABLE *SystemTable) {
    gST = SystemTable;
    gBS = gST->BootServices;
    gRS = gST->RuntimeServices;

    return 0;
}


#endif      // __GLOBAL__

