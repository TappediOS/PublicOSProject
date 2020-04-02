// **********************************
//  SystemStruct.h
//  Update  develop0.1
// **********************************

#include <DType.h>
#include <IOStruct.h>
#include <MemoryStruct.h>

#ifndef __SYSTEMSTRUCT__
#define __SYSTEMSTRUCT__

// ******************************************
//      TableHeader
//  UEFI.Spec 4-2
//  Update  develop0.1
// ******************************************
typedef struct {
    UINT64  Signature;
    UINT32  Revision;
    UINT32  HeaderSize;
    UINT32  CRC32;
    UINT32  Reserved;
} EFI_TABLE_HEADER;


// ******************************************
//      Runtime Services Table
//  UEFI.Spec 4-5
//  Update  develop0.1
// ******************************************
typedef struct EFI_RUNTIME_SERVICES {
    //
    // Time Services
    // UEFI.Spec 7-3
    // Update  develop0.1
    //
    EFI_STATUS  GetTime;
    EFI_STATUS  SetTime;
    EFI_STATUS  GetWakeupTime;
    EFI_STATUS  SetWakeupTime;

    //
    // Virtual Memory Services
    // UEFI.Spec 7-4
    // Update  develop0.1
    //
    EFI_STATUS  SetVirtualAddressMap;
    EFI_STATUS  ConvertPointer;

    //
    // Variable Services
    // UEFI.Spec 7-2
    // Update  develop0.1
    //
    EFI_STATUS  GetVariable;
    EFI_STATUS  GetNextVariableName;
    EFI_STATUS  SetVariable;

    //
    // Miscellaneous Services
    // UEFI.Spec 7-5
    // Update  develop0.1
    //
    EFI_STATUS  GetNextHighMonotonicCount;
    VOID        (*ResetSystem) ();

    //
    // UEFI 2.0 Capsule Services
    // UEFI.Spec 7-5
    // Update  develop0.1
    //
    EFI_STATUS  UpdateCapsule;
    EFI_STATUS  QueryCapsuleCapabilities;

    //
    // Miscellaneous UEFI 2.0 Service
    // UEFI.Spec 7-2
    // Update  develop0.1
    //
    EFI_STATUS  QueryVariableInfo;
} EFI_RUNTIME_SERVICES;


// ******************************************
//      TaskPriority
//  UEFI.Spec 6-1
//  Update  develop0.1
// ******************************************
typedef UINTN   EFI_TPL;

#define TPL_APPLICATION     4
#define TPL_CALLBACK        8
#define TPL_NOTIFY          16
#define TPL_HIGH_LEVEL      31

// ******************************************
//      Protocol Handler Services
//  UEFI.Spec 6-3
//  Update  develop1.0
// ******************************************
#define EFI_OPEN_PROTOCOL_BY_HANDLE_PROTOCOL    0x00000001
#define EFI_OPEN_PROTOCOL_GET_PROTOCOL          0x00000002
#define EFI_OPEN_PROTOCOL_TEST_PROTOCOL         0x00000004
#define EFI_OPEN_PROTOCOL_BY_CHILD_CONTROLLER   0x00000008
#define EFI_OPEN_PROTOCOL_BY_DRIVER             0x00000010
#define EFI_OPEN_PROTOCOL_EXCLUSIVE             0x00000020

// ******************************************
//      BootServices
//  UEFI.Spec 4-4
//  Update  develop1.1
// ******************************************
typedef struct {
    EFI_TABLE_HEADER        Hdr;

    //
    // TaskPriority Services
    // UEFI.Spec 6-1
    // Update  develop0.1
    //
    EFI_TPL     RaiseTPL;
    VOID        (*RestoreTPL) ();

    //
    // Memory Services
    // UEFI.Spec 6-2
    // Update  develop1.1
    //
    EFI_STATUS  (*AllocatePages) (
            EFI_ALLOCATE_TYPE       Type,
            EFI_MEMORY_TYPE         MemoryType,
            UINTN                   Pages,
            EFI_PHYSICAL_ADDRESS    *Memory
    );
    EFI_STATUS  FreePages;
    EFI_STATUS  (*GetMemoryMap) (
            UINTN *MemoryMapSize,
            EFI_MEMORY_DESCRIPTOR *MemoryMap,
            UINTN *MapKey,
            UINTN *DescriptorSize,
            UINT32 *DescriptorVersion
    );
    EFI_STATUS  (*AllocatePool) (
            EFI_MEMORY_TYPE PoolType,
            UINTN Size,
            VOID **Buffer
    );
    EFI_STATUS  (*FreePool) (
            VOID* Buffer
    );

    //
    // Event and Timer Services
    // UEFI.Spec 6-1
    // Update  develop0.1
    //
    EFI_STATUS  CreateEvent;
    EFI_STATUS  SetTimer;
    EFI_STATUS  WaitForEvent;
    EFI_STATUS  SignalEvent;
    EFI_STATUS  CloseEvent;
    EFI_STATUS  CheckEvent;

    //
    // Protocol Handler Services
    // UEFI.Spec 6-3
    // Update  develop0.1
    //
    EFI_STATUS  InstallProtocolInterface;
    EFI_STATUS  ReinstallProtocolInterface;
    EFI_STATUS  UninstallProtocolInterface;

    EFI_STATUS  (*HandleProtocol) (
            EFI_HANDLE  Handle,
            EFI_GUID    *Protocol,
            VOID        **Interface
    );

    VOID*       Reserved;
    EFI_STATUS  RegisterProtocolNotify;
    EFI_STATUS  LocateHandle;
    EFI_STATUS  LocateDevicePath;
    EFI_STATUS  InstallConfigurationTable;

    //
    // Image Services
    // UEFI.Spec 6-4
    // Update  develop0.1
    //
    EFI_STATUS  LoadImage;
    EFI_STATUS  StartImage;
    EFI_STATUS  Exit;
    EFI_STATUS  UnloadImage;
    EFI_STATUS  (*ExitBootServices) (
            EFI_HANDLE  ImageHandle,
            UINTN       MapKey
    );

    //
    // Miscellaneous Services
    // UEFI.Spec 6-5
    // Update  develop0.1
    //
    EFI_STATUS  GetNextMonotonicCount;
    EFI_STATUS  Stall;
    EFI_STATUS  SetWatchdogTimer;

    //
    // Driver Support Services
    // UEFI.Spec 6-3
    // Update  develop0.1
    //
    EFI_STATUS  ConnectController;
    EFI_STATUS  DisConnectContoroller;

    //
    // Open and Close Protocol Services
    // UEFI.Spec 6-3
    // Update  develop1.0
    //
    EFI_STATUS  (*OpenProtocol) (
            EFI_HANDLE  Handle,
            EFI_GUID    *Protocol,
            VOID        **Interface,     // option
            EFI_HANDLE  AgentHandle,
            EFI_HANDLE  ControllerHandle,
            UINT32      Attributes
    );
    EFI_STATUS  (*CloseProtocol) (
            EFI_HANDLE  Handle,
            EFI_GUID    *Protocol,
            EFI_HANDLE  AgentHandle,
            EFI_HANDLE  ControllerHandle
    );
    EFI_STATUS  OpenProtocolInformation;

    //
    // Library Services
    // UEFI.Spec 6-3
    // Update  develop0.1
    //
    EFI_STATUS  ProtocolsPerHandle;
    EFI_STATUS  LocateHandleBuffer;
    EFI_STATUS  (*LocateProtocol) (
            EFI_GUID    *Protocol,
            VOID        *Registration,
            VOID        **Interface
    );
    EFI_STATUS  InstallMultipleProtocolInterfaces;
    EFI_STATUS  UninstallMultipleProtocolInterfaces;

    //
    // 32-bit CRC Services
    // UEFI.Spec 6-5
    // Update  develop0.1
    //
    EFI_STATUS  CalculateCrc32;

    //
    // Miscellaneous Services
    // UEFI.Spec 6-5
    // Update  develop0.1
    //
    VOID        (*CopyMem) (
            VOID   *Destination,
            VOID   *Source,
            UINTN  Length
    );
    VOID        (*SetMem) ();
    EFI_STATUS  CreaetEventEx;
} EFI_BOOT_SERVICES;

// ******************************************
//      EFI Configuration Table
//  UEFI.Spec 4-6
//  Update  develop0.1
// ******************************************
typedef struct {
    EFI_GUID    VendorGuid;
    VOID        *VendorTable;
} EFI_CONFIGURATION_TABLE;

/**  efi_acpi_guid  **/

// ******************************************
//      SystemTable
//  UEFI.Spec 4-3
//  Update  develop0.1
// ******************************************
typedef struct EFI_SYSTEM_TABLE {
    EFI_TABLE_HEADER                Hdr;
    CHAR16                          *FirmwareVendor;
    UINT32                          FirmwareRevision;
    EFI_HANDLE                      ConsoleInHandle;
    EFI_SIMPLE_TEXT_INPUT_PROTOCOL  *ConIn;
    EFI_HANDLE                      ConsoleOutHandle;
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *ConOut;
    EFI_HANDLE                      StandardErrorHandle;
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *StdErr;
    EFI_RUNTIME_SERVICES            *RuntimeServices;
    EFI_BOOT_SERVICES               *BootServices;
    UINTN                           NumberOfTableEntries;
    EFI_CONFIGURATION_TABLE         *ConfigurationTable;
} EFI_SYSTEM_TABLE;


#endif      // __SYSTEMSTRUCT__

