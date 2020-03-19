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

#define KERNEL_ENTRY    0x100000

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
    Status = gBS->AllocatePages(
            AllocateAnyPages,
            EfiLoaderData,
            (KernelFileSize + 4095) / 4096,
            &KernelFilePointer);
    if (Status != EFI_SUCCESS) {
        printf(L"[Fatal] Allocate Kernel File Buffer Error : %d\r\n", Status);
        return Status;
    }
    printf(L"[Success] Allocate Kernel File Buffer\r\n");

    // Read the Kernel File Header
    struct test {
        void *bss_start;
        unsigned long long bss_size;
    } test;
    unsigned long long test_size = sizeof(test);
    Status = kernel->Read(kernel, &test_size, (void*)&test);
    if (Status != EFI_SUCCESS) {
        printf(L"[Fatal] TEST READ ERROR : %s\r\n", err_msg[Status]);
        while (1);
        return Status;
    }
    printf(L"[Success] TEST READ\r\n");


    KernelHeader    header;
    char buf[256];
    UINTN           KernelHeaderSize = 0x10;
    Status = kernel->Read(kernel, &KernelHeaderSize, (VOID*)&buf);
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

    Status = kernel->Close(kernel);
    if (Status != EFI_SUCCESS) {
        printf(L"[Fatal] Kernel Close Error : %s\r\n", err_msg[Status]);
        return Status;
    }
    printf(L"[Success] Kernel Close\r\n");


    printf(L"[Success] open file protocol for the root SUCCESS\r\n");
    while (1);

    return 0;
}


