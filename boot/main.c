// **********************************
//  main.c
//  update  ver.develop0.1
// **********************************

#include "global.h"

#include <DType.h>
#include <SystemStruct.h>
#include <FileStruct.h>
#include <GraphicStruct.h>

#include <stdio.h>
#include <string.h>

#define GRAPHICS_INFO   0x100000

#define KERNEL_ENTRY    0x110000

#define MEM_DESC_SIZE   4096

typedef struct KernelHeader {
    char buf[0x100];
} KernelHeader;

typedef struct GraphicsInfo {
    unsigned long *vram;
    unsigned short int width;
    unsigned short int height;
} GraphicsInfo;

EFI_STATUS efiMain(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable) {
    initGlobal(SystemTable);

    EFI_STATUS  Status;
    Status = SystemTable->ConOut->ClearScreen(SystemTable->ConOut);

    // get graphics
    EFI_GRAPHICS_OUTPUT_PROTOCOL *graphics = NULL;
    GraphicsInfo *graphicsInfo = (GraphicsInfo *)GRAPHICS_INFO;
    Status = gBS->LocateProtocol(&gEfiGraphicsOutputProtocolGuid, NULL, (void**)&graphics);
    if (Status != EFI_SUCCESS) {
        printf(L"[Fatal] GraphicOutputProtocol Locate Error : %s\r\n", err_msg[Status]);
        while (1);
        return 0;
    }
    printf(L"[Success] GraphicOutputProtocol Locate\r\n");

    graphicsInfo->vram   = (unsigned long *)graphics->Mode->FrameBufferBase;
    graphicsInfo->width  = (unsigned short int)graphics->Mode->Info->HorizontalResolution;
    graphicsInfo->height = (unsigned short int)graphics->Mode->Info->VerticalResolution;

    // for (int o = 0; o < 0xFFFF; o++)
        // graphicsInfo->vram[o] = 0xFF00FF;

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
    CHAR16 *FilePath = L"\\kernel.bin";
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
    UINTN           KernelHeaderSize = sizeof(header);
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
    UINT64 *KernelBuffer = NULL;
    Status = kernel->Read(kernel, &KernelFileSize, (VOID*)KERNEL_ENTRY);
    if (Status != EFI_SUCCESS) {
        printf(L"[Fatal] Kernel Main Read Error : %d\r\n", Status);
        return Status;
    }
    printf(L"[Success] Kernel Main Read\r\n");
/*
    // print MainKernel head
    printf(L"[Info]Kernel(Buffer : 0x%x) : ", KernelBuffer);
    UINTN   i;
    CHAR8 *p = (CHAR8*) KernelBuffer;
    for (i = 0; i < 0x10; i++)
        printf(L"%x ", *p++);
    printf(L"\r\n");


    // Write Kernel to Memory
    UINT64 *KernelStart = (UINT64 *)KERNEL_ENTRY;
    gBS->CopyMem(KernelStart, KernelBuffer, KernelFileSize);
    printf(L"[Success]Kernel Copy Memory\r\n");
*/
    Status = kernel->Close(kernel);
    if (Status != EFI_SUCCESS) {
        printf(L"[Fatal] Kernel Close Error : %s\r\n", err_msg[Status]);
        return Status;
    }
    printf(L"[Success] Kernel Close\r\n");
    printf(L"[Info]SystemTable : 0x%x\r\n", SystemTable);

    // print MainKernel head
    printf(L"[Info]Kernel(Memory : 0x%x) : ", KERNEL_ENTRY);
    UINTN i;
    CHAR8 *p = (CHAR8*) KERNEL_ENTRY;
    for (i = 0; i < 0x20; i++)
        printf(L"%x ", *p++);
    printf(L"\r\n");
    printf(L"[Info]VRAM : 0x%x\r\n", graphicsInfo->vram);

    for (i = 0; i < 10; i++) {
        printf(L"======================================================\r\n");
        printf(L"[Info] Number Of Boot : %d\r\n", i);
        // exit boot services
        UINTN           mapSize = 0;
        UINTN           mapKey = 0;
        UINTN           descSize;
        UINT32          descVersion;
        EFI_MEMORY_DESCRIPTOR   *memoryMap = NULL;
        Status = gBS->GetMemoryMap(&mapSize, memoryMap, &mapKey, &descSize, &descVersion);
        printf(L"[Info] GetMemoryMap : %d\r\n", (Status & 0xFF));

        while ((Status & 0xFF) == EFI_BUFFER_TOO_SMALL) {
            if (memoryMap) {
                Status = gBS->FreePool(memoryMap);
            }
            mapSize += 0x1000;
            Status = gBS->AllocatePool(EfiLoaderData, mapSize, (void**)&memoryMap);
            printf(L"[Info] AllocatePool : %d\r\n", (Status & 0xFF));
            Status = gBS->GetMemoryMap(&mapSize, memoryMap, &mapKey, &descSize, &descVersion);
            printf(L"[Info] GetMemoryMap : %d\r\n", (Status & 0xFF));
        }
        printf(L"-----  Memory Info  -----\r\n");
        printf(L"memoryMap : 0x%x\r\n", memoryMap);
        printf(L"mapSize   : 0x%x\r\n", mapSize);
        printf(L"mapKey    : 0x%x\r\n", mapKey);

        Status = gBS->ExitBootServices(ImageHandle, mapKey);
        if (Status != EFI_SUCCESS) {
            printf(L"[Fatal] ExitBootServices : %s(%d)\r\n\r\n", err_msg[(Status & 0xFF)], (Status & 0xFF));
        }
        else {
            __asm__("jmp    *0x00110000\n");
            while (1);
            return 0;
        }
    }
    printf(L"Boot Error\r\n");

    while (1);

    return 0;
}


