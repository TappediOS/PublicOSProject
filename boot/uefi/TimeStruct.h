// ************************************
//      TimeStruct.h
//  update  ver.develop1.0
// ************************************

#include <DType.h>

#ifndef __TIMESTRUCT__
#define __TIMESTRUCT__


// ************************************
//      EFI TIME
//  UEFI.Spec 7-3
//  update  ver.develop1.0
// ************************************

typedef struct EFI_TIME {
    UINT16 Year;
    UINT8  Month;
    UINT8  Day;
    UINT8  Hour;
    UINT8  Minute;
    UINT8  Second;
    UINT8  Padl;
    UINT32 Nanosecond;
    INT16  TimeZone;
    UINT8  Daylight;
    UINT8  Pad2;
} EFI_TIME;


#endif      // __TIMESTRUCT__

