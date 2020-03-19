// DType.h
// Update ver.develop0.1

#ifndef __DTYPE__
#define __DTYPE__

// type defined

typedef char                BOOLEAN;

#define FALSE   0
#define TRUE    1

typedef signed long long int     INTN;
typedef unsigned long long int   UINTN;

typedef signed char         INT8;
typedef unsigned char       UINT8;

typedef signed short int    INT16;
typedef unsigned short int  UINT16;

typedef signed int          INT32;
typedef unsigned int        UINT32;

typedef signed long long int     INT64;
typedef unsigned long long int   UINT64;

typedef unsigned char       CHAR8;
typedef unsigned short int  CHAR16;

typedef void                VOID;

typedef struct {
    UINT32  Data1;
    UINT16  Data2;
    UINT16  Data3;
    UINT8   Data4[8];
} GUID;

typedef GUID EFI_GUID;

typedef unsigned long long  EFI_STATUS;
typedef VOID*               EFI_HANDLE;
typedef VOID*               EFI_EVENT;

#define NULL    0


// error defined
#define EFI_SUCCESS     0

#define EFI_LOAD_ERROR          1
#define EFI_INVALID_PARAMATER   2

#endif      // __DTYPE__

