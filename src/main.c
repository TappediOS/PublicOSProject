// **********************************
//  main.c
//  update  ver.develop0.1
// **********************************

#include "global.h"

#include <DType.h>
#include <SystemStruct.h>
#include <FileStruct.h>

#include <stdio.h>
#include <string.h>


EFI_STATUS efiMain(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable) {
    initGlobal(SystemTable);

    EFI_STATUS  Status;
    Status = SystemTable->ConOut->ClearScreen(SystemTable->ConOut);

    // open root dir
    EFI_FILE_PROTOCOL *root = NULL;
    EFI_SIMPLE_FILE_SYSTEM_PROTOCOL *SimpleFileSystem;
    EFI_LOADED_IMAGE_PROTOCOL   *LoadedImage;
    // OpenFileProtocolForThisAppRootDir(ImageHandle, &RootDir);
    // OpenSimpleFileSystemProtocol(ImageHandle, &SimpleFileSystem, &SimpleFileSystemOpener)

    Status = gBS->OpenProtocol(
            ImageHandle,
            &gEfiLoadedImageProtocolGuid,
            (VOID**)&LoadedImage,
            ImageHandle,
            NULL,
            EFI_OPEN_PROTOCOL_GET_PROTOCOL);
    if (Status != EFI_SUCCESS) {
        printf(L"[Fatal] Open Protocol of LoadedImage Error : %d\r\n", Status);
        return Status;
    }
    printf(L"[Success] Open Protocol of LoadedImage\r\n");

    // **SimpleFileSystemOpener = LoadedImage->DeviceHandle;
    Status = gBS->OpenProtocol(
            LoadedImage->DeviceHandle,
            &gEfiSimpleFileSystemProtocolGuid,
            (VOID**)&SimpleFileSystem,
            ImageHandle,
            NULL,
            EFI_OPEN_PROTOCOL_GET_PROTOCOL);
    if (Status != EFI_SUCCESS) {
        printf(L"[Fatal] Open Protocol of SimpleFileSystem Error : %d\r\n", Status);
        return Status;
    }
    printf(L"[Success] Open Protocol of SimpleFileSystem\r\n");

    Status = SimpleFileSystem->OpenVolume(SimpleFileSystem, &root);
    if (Status != EFI_SUCCESS) {
        printf(L"[Fatal] Open Volume of root Error : %d\r\n", Status);
        return Status;
    }
    printf(L"[Success] Open Volume of root\r\n");

    // open kernel file
    EFI_FILE_PROTOCOL *kernel;
    CHAR16 *FilePath = L"\\kernel.elf";
    Status = root->Open(root, &kernel, FilePath, EFI_FILE_MODE_READ, 0);
    if (Status != EFI_SUCCESS) {
        printf(L"[Fatal] Kernel Open Error : %d\r\n", Status);
        return Status;
    }

    UINTN   FileInfoBufSize = sizeof(EFI_FILE_INFO) + sizeof(CHAR16) * strlen(FilePath) + 2;
    UINT8   FileInfoBuf[FileInfoBufSize];
    Status = kernel->GetInfo(kernel, &gEfiFileInfoGuid, &FileInfoBufSize, FileInfoBuf);
    if (Status != EFI_SUCCESS) {
        printf(L"[Fatal] Get Kernel Info Error : %d\r\n", Status);
        return Status;
    }

    EFI_FILE_INFO *FileInfo = (EFI_FILE_INFO*)FileInfoBuf;
    printf(L"-----   Kernel Info   -----\r\n");
    printf(L"Size     : 0x%x\r\n", FileInfo->Size);
    printf(L"FileSize : 0x%x\r\n", FileInfo->FileSize);
    printf(L"FileName : %s\r\n", FileInfo->FileName);

    printf(L"[Success] open file protocol for the root SUCCESS\r\n");
    while (1);

    return 0;
}


