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

#define KERNEL_ENTRY    0x110000

#define MEM_DESC_SIZE   4096

typedef struct KernelHeader {
    void *BssStart;
    unsigned long long BssSize;
} KernelHeader;

EFI_STATUS efiMain(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable) {
    initGlobal(SystemTable);

    EFI_STATUS  Status;
    Status = SystemTable->ConOut->ClearScreen(SystemTable->ConOut);

    // open root dir
    EFI_FILE_PROTOCOL *root = NULL;
    EFI_SIMPLE_FILE_SYSTEM_PROTOCOL *SimpleFileSystem;
    EFI_LOADED_IMAGE_PROTOCOL   *LoadedImage;

    Status = gBS->OpenProtocol(
            ImageHandle,
            &gEfiLoadedImageProtocolGuid,
            (VOID**)&LoadedImage,
            ImageHandle,
            NULL,
            EFI_OPEN_PROTOCOL_GET_PROTOCOL);
    if (Status != EFI_SUCCESS) {
        printf(L"[Fatal] Open Protocol of LoadedImage Error : %s\r\n", err_msg[Status]);
        return Status;
    }
    printf(L"[Success] Open Protocol of LoadedImage\r\n");

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
    printf(L"[Success] Kernel Open\r\n");

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

    // allocate buf for the kernel size
    EFI_PHYSICAL_ADDRESS    KernelFilePointer = 0;
    UINTN                   KernelFileSize = FileInfo->FileSize;

    // Read the Kernel File Header
    KernelHeader    header;
    UINTN           KernelHeaderSize = sizeof(KernelHeader);
    Status = kernel->Read(kernel, &KernelHeaderSize, (VOID*)&header);
    if (Status != EFI_SUCCESS) {
        printf(L"[Fatal] Kernel Header Read Error : %d\r\n", Status);
        return Status;
    }
    //
    // header validation
    //
    printf(L"[Success] Kernel Header Read\r\n");

    // Read Kernel Main
    KernelFileSize -= KernelHeaderSize;
    Status = kernel->Read(kernel, &KernelFileSize, (void*)KERNEL_ENTRY);
    if (Status != EFI_SUCCESS) {
        printf(L"[Fatal] Kernel Main Read Error : %d\r\n", Status);
        return Status;
    }
    printf(L"[Success] Kernel Main Read\r\n");

    // print MainKernel head
    printf(L"Kernel : ");
    UINTN   i;
    CHAR8 *p = (CHAR8*) KERNEL_ENTRY;
    for (i = 0; i < 0x10; i++)
        printf(L"%x ", *p++);
    printf(L"\r\n");

    // Write Kernel to Memory ???
    // Status = gBS->CopyMem(, KERNEL_ENTRY, KernelFileSize);

    Status = kernel->Close(kernel);
    if (Status != EFI_SUCCESS) {
        printf(L"[Fatal] Kernel Close Error : %s\r\n", err_msg[Status]);
        return Status;
    }
    printf(L"[Success] Kernel Close\r\n");
    printf(L"[Info]SystemTable : 0x%x\r\n", SystemTable);

    // exit boot services
    UINTN           mapSize = 0;
    UINTN           mapKey;
    UINTN           descSize;
    UINT32          descVersion;
    EFI_MEMORY_DESCRIPTOR   *memoryMap = NULL;
    do {
        Status = gBS->GetMemoryMap(&mapSize, memoryMap, &mapKey, &descSize, &descVersion);
        while (Status == EFI_BUFFER_TOO_SMALL) {
            if (memoryMap) {
                gBS->FreePool(memoryMap);
            }
            mapSize += 0x1000;
            Status = gBS->AllocatePool(EfiLoaderData, mapSize, (void**)&memoryMap);
            Status = gBS->GetMemoryMap(&mapSize, memoryMap, &mapKey, &descSize, &descVersion);
        }
        Status = gBS->ExitBootServices(ImageHandle, mapKey);
        if (Status != EFI_SUCCESS) {
            printf(L"[Fatal] ExitBootServices : %s(%d)\r\n", err_msg[Status], Status);
            while (1);
            return Status;
        }
    } while (Status != EFI_SUCCESS);
    __asm__ (" jmp 0x110000\n");

    while (1);

    return 0;
}


