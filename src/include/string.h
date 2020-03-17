// **************************************
//      string.h
// update  ver.develop1.0
// **************************************

#include <DType.h>

UINTN strlen(const CHAR16 *s);

#ifndef __STRING__
#define __STRING__

UINTN strlen(const CHAR16 *s) {
    int len = 0;
    while (*s++) len++;
    return len;
}


#endif      // __STRING__

