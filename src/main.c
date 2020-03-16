// **********************************
//  main.c
//  update  ver.develop0.1
// **********************************

#include "global.h"

#include <DType.h>
#include <SystemStruct.h>

EFI_STATUS OpenRootFileDir(EFI_HANDLE ImageHandle, EFI_FILE_PROTOCOL **root);

EFI_STATUS efiMain(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable) {
    initGlobal(SystemTable);

    gST->ConOut->ClearScreen(gST->ConOut);

    EFI_STATUS  Status;

    // Get Handle of Root Directory
    EFI_FILE_PROTOCOL *root = NULL;
    Status = OpenRootFileDir(ImageHandle, &root);
    if (Status == EFI_ERROR) {
        gST->ConOut->OutputString(gST->ConOut, L"Could not open file protocol for the root: %r\r\n", Status);
        return Status;
    }

    while (1);

    return 0;
}

EFI_STATUS OpenRootFileDir(EFI_HANDLE ImageHandle, EFI_FILE_PROTOCOL **root) {


    return 0;
}



