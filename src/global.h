// global.h
// update  ver.develop0.1

#include <IOStruct.h>
#include <SystemStruct.h>

#ifndef __GLOBAL__
#define __GLOBAL__

EFI_SYSTEM_TABLE        *gST = NULL;
EFI_BOOT_SERVICES       *gBT = NULL;
EFI_RUNTIME_SERVICES    *gRS = NULL;

EFI_STATUS initGlobal(EFI_SYSTEM_TABLE *SystemTable) {
    gST = SystemTable;
    gBT = gST->BootServices;
    gRS = gST->RuntimeServices;

    return 0;
}


#endif      // __GLOBAL__
/*
int printf(CHAR16 *s, ...) {
    int i, d, ret = 0;
    CHAR16 *t, ch[2], num[32];
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
                d = va_arg(ap, int);
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
                d = va_arg(ap, int);
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
*/

