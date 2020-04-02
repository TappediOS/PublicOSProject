// *************************************
//      stdio.h
//  Update  ver.develop1.0
// *************************************

#include <stdarg.h>

#include <DType.h>
#include <SystemStruct.h>
#include <IOStruct.h>

int printf(CHAR16 *s, ...);


#ifndef __STDIO__
#define __STDIO__

#define STDIO_BUF_LENGTH 64


int printf(CHAR16 *s, ...) {
    unsigned long long i, d;
    int ret = 0;
    CHAR16 *t, ch[2], num[STDIO_BUF_LENGTH];
    va_list ap;
    CHAR16 sx[] = {
        L'0', L'1', L'2', L'3', L'4', L'5', L'6', L'7',
        L'8', L'9', L'A', L'B', L'C', L'D', L'E', L'F'};

    va_start(ap, s);
    do {
        switch(*s) {
        case L'%':
            s++;
            switch (*s) {
            case L'd':
                i = 0;
                d = va_arg(ap, unsigned long long);
                do {
                    num[i++] = (d % 10) + L'0';
                } while(d /= 10);
                while (i--)
                    printf(L"%c", num[i]);
                break;
            case L'c':
                ch[0] = va_arg(ap, int);
                ch[1] = L'\0';
                gST->ConOut->OutputString(gST->ConOut, ch);
                break;
            case L'x':
                i = 0;
                d = va_arg(ap, unsigned long long);
                do {
                    num[i++] = sx[d % 16];
                } while(d /= 16);
                while (i--)
                    printf(L"%c", num[i]);
                break;
            case L's':
                t = va_arg(ap, CHAR16*);
                printf(t);
                break;
            }
            break;
        default:
            ch[0] = *s;
            ch[1] = L'\0';
            gST->ConOut->OutputString(gST->ConOut, ch);
            break;
        }
    } while(*s++);

    va_end(ap);
    return ret;
}


#endif      // __STDIO__


