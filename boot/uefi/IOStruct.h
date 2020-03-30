// *********************************
//      IOStruct.h
// Update  develop0.1
// *********************************

#include <DType.h>

#ifndef __IOSTRUCT__
#define __IOSTRUCT__


// _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
//      Simple Text Input Protocol
//  UEFI.Spec 11-3
//  Update  develop0.1
// _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

// ************************************
//  EFI_INPUT_KEY
//  Update  develop0.1
// ************************************
typedef struct {
    UINT16  ScanCode;
    CHAR16  UnicodeChar;
} EFI_INPUT_KEY;

// ************************************
//  EFI_SIMPLE_TEXT_INPUT_PROTOCOL
//  Update  develop0.1
// ************************************
typedef struct EFI_SIMPLE_TEXT_INPUT_PROTOCOL {
    EFI_STATUS  Reset;
    EFI_STATUS  ReadKeyStroke;
    EFI_EVENT   WaitForKey;
} EFI_SIMPLE_TEXT_INPUT_PROTOCOL;


// _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
//      Simple Text Output Protocol
//  UEFI.Spec 11-3
//  Update  develop0.1
// _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

// ************************************
//  SIMPLE_TEXT_OUTPUT_MODE
//  Update  develop0.1
// ************************************
typedef struct SIMPLE_TEXT_OUTPUT_MODE {
    INT32   MaxMode;
    INT32   Mode;
    INT32   Attribute;
    INT32   CursorColumn;
    INT32   CursorRow;
    BOOLEAN CursorVisible;
} SIMPLE_TEXT_OUTPUT_MODE;

// ************************************
//  EFI_SIMPLE_OUTPUT_PROTOCOL
//  Update  develop1.0
// ************************************
#define EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_GUID \
    { 0x387477C2, 0x69C7, 0x11D2, \
        { 0x8E, 0x39, 0x00, 0xA0, 0xC9, 0x69, 0x72, 0x3B }}
EFI_GUID gEfiSimpleTextOutputProtocolGuid = EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_GUID;

typedef struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL {
    EFI_STATUS  Reset;

    EFI_STATUS  (*OutputString) (
            struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL  *This,
            CHAR16                                  *String
    );

    EFI_STATUS  TestString;
    EFI_STATUS  QueryMode;
    EFI_STATUS  SetMode;
    EFI_STATUS  SetAttribute;

    EFI_STATUS  (*ClearScreen) (
            struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This
    );

    EFI_STATUS  SetCursorPosition;
    EFI_STATUS  EnableCursor;
    SIMPLE_TEXT_OUTPUT_MODE *Mode;
} EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL;

#endif      // __IOSTRUCT__

