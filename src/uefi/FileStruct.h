// ******************************************
//  FileStruct.h
//  Update  develop1.0
// ******************************************

#include <DType.h>
#include <SystemStruct.h>
#include <TimeStruct.h>

#ifndef __FILESTRUCT__
#define __FILESTRUCT__

struct EFI_FILE_PROTOCOL;

// ******************************************
//      EFI Loaded Image Protocol
//  UEFI.Spec 8-1
//  Update  develop1.0
// ******************************************
#define EFI_LOADED_IMAGE_PROTOCOL_GUID\
    {0x5B1B31A1,0x9562,0x11d2,\
        {0x8E,0x3F,0x00,0xA0,0xC9,0x69,0x72,0x3B}}

EFI_GUID gEfiLoadedImageProtocolGuid = EFI_LOADED_IMAGE_PROTOCOL_GUID;

//
// EFI Device Path Protocol
// UEFI.Spec 9-2
// Update  develop1.0
//
typedef struct EFI_DEVICE_PATH_PROTOCOL {
    UINT8   Type;
    UINT8   SubType;
    UINT8   Length[2];
} EFI_DEVICE_PATH_PROTOCOL;

typedef struct EFI_LOADED_IMAGE_PROTOCOL {
    UINT32              Revision;
    EFI_HANDLE          ParentHandle;
    EFI_SYSTEM_TABLE    *SystemTable;

    // Source location of the image
    EFI_HANDLE          DeviceHandle;
    EFI_DEVICE_PATH_PROTOCOL
                        *FilePath;
    VOID                *Reserved;

    // Image's load options
    UINT32              LoadOptionSize;
    VOID                *LoadOptions;

    // Location where image was loaded
    VOID                *ImageBase;
    UINT64              ImageSize;
    EFI_MEMORY_TYPE     ImageCodeType;
    EFI_MEMORY_TYPE     ImageDataType;
    EFI_STATUS          Unload;
} EFI_LOADED_IMAGE_PROTOCOL;


// ******************************************
//      Simple File System Protocol
//  UEFI.Spec 12-4
//  Update  develop1.0
// ******************************************

#define EFI_SIMPLE_FILE_SYSTEM_PROTOCOL_GUID \
    {0x0964e5b22,0x6459,0x11d2,\
        {0x8e,0x39,0x00,0xa0,0xc9,0x69,0x72,0x3b}}

EFI_GUID gEfiSimpleFileSystemProtocolGuid = EFI_SIMPLE_FILE_SYSTEM_PROTOCOL_GUID;

typedef struct EFI_SIMPLE_FILE_SYSTEM_PROTOCOL {
    UINT64      Revision;
    EFI_STATUS  (*OpenVolume)(
            struct EFI_SIMPLE_FILE_SYSTEM_PROTOCOL *This,
            struct EFI_FILE_PROTOCOL               **Root
    );
} EFI_SIMPLE_FILE_SYSTEM_PROTOCOL;

// ******************************************
//      EFI File Info
//  UEFI.Spec 12-5
//  update  ver.develop1.0
// ******************************************

//
// File Attribute Bits
//
#define EFI_FILE_READ_ONLY  0x0000000000000001
#define EFI_FILE_HIDDEN     0x0000000000000002
#define EFI_FILE_SYSTEM     0x0000000000000004
#define EFI_FILE_RESERVED   0x0000000000000008
#define EFI_FILE_DIRECTORY  0x0000000000000010
#define EFI_FILE_ARCHIVE    0x0000000000000020
#define EFI_FILE_VALID_ATTR 0x0000000000000037

#define EFI_FILE_INFO_GUID \
    { 0x09576E92, 0x6D3F, 0x11D2, \
        {0x8E, 0x39, 0x00, 0xA0, 0xC9, 0x69, 0x72, 0x3B }}

GUID gEfiFileInfoGuid = EFI_FILE_INFO_GUID;

typedef struct EFI_FILE_INFO {
    UINT64      Size;
    UINT64      FileSize;
    UINT64      PhysicalSize;
    EFI_TIME    CreateTime;
    EFI_TIME    LastAccessTime;
    EFI_TIME    ModificationTime;
    UINT64      Attribute;
    CHAR16      FileName[];
} EFI_FILE_INFO;


// ******************************************
//      File Open Modes
// ******************************************
#define EFI_FILE_MODE_READ      0x0000000000000001
#define EFI_FILE_MODE_WRITE     0x0000000000000002
#define EFI_FILE_MODE_CREATE    0x8000000000000000

// ******************************************
//      File Attributes
// ******************************************
#define EFI_FILE_READ_ONLY  0x0000000000000001
#define EFI_FILE_HIDDEN     0x0000000000000002
#define EFI_FILE_SYSTEM     0x0000000000000004
#define EFI_FILE_RESERVED   0x0000000000000008
#define EFI_FILE_DIRECTORY  0x0000000000000010
#define EFI_FILE_ARCHIVE    0x0000000000000020
#define EFI_FILE_VALID_ATTR 0x0000000000000037

// ******************************************
//      File Protocol
//  UEFI.Spec 12-5
//  Update  develop1.0
// ******************************************

typedef struct EFI_FILE_PROTOCOL {
    UINT64          Revision;
    EFI_STATUS      (*Open) (
            struct EFI_FILE_PROTOCOL *This,
            struct EFI_FILE_PROTOCOL **NewHandle,
            CHAR16 *FileName,
            UINT64 OpenMode,
            UINT64 Attributes
    );
    EFI_STATUS      (*Close) (
            struct EFI_FILE_PROTOCOL *This
    );
    EFI_STATUS      Delete;
    EFI_STATUS      (*Read) (
            struct EFI_FILE_PROTOCOL    *This,
            UINTN                       *BufferSize,
            VOID                        *Buffer
    );
    EFI_STATUS      Write;
    EFI_STATUS      GetPosition;
    EFI_STATUS      SetPosition;
    EFI_STATUS (*GetInfo) (
            struct EFI_FILE_PROTOCOL *This,
            EFI_GUID    *InfomationType,
            UINTN       *BufferSize,
            VOID        *Buffer
    );
    EFI_STATUS      SetInfo;
    EFI_STATUS      Flush;
    EFI_STATUS      OpenEx;
    EFI_STATUS      ReadEx;
    EFI_STATUS      WriteEx;
    EFI_STATUS      FlushEx;
} EFI_FILE_PROTOCOL;

#endif      // __FILESTRUCT__

