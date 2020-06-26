// ***********************************
//  include - util - stdio.h
//  Update  develop3.0
// ***********************************

#include <types.h>

#ifndef __STDIO__
#define __STDIO__

#define TYPE_UCHAR      1
#define TYPE_UINT       2
#define TYPE_ULLINT     3
#define TYPE_UINTX      4
#define TYPE_ULLINTX    5
#define TYPE_SCHAR      11
#define TYPE_SINT       12
#define TYPE_SLLINT     13
#define TYPE_SINTX      13
#define TYPE_SLLINTX    14

typedef union {
    unsigned char uc;
    unsigned int ud;
    unsigned long long int ulld;
    signed char sc;
    signed int sd;
    signed long long int slld;
} ATYPE;

void value2str(ATYPE val, char *buf, char type, unsigned char mf, unsigned char zf, unsigned char dig);
int sprintf(char *s, const char *t, ...);
void pmem(char *s, char *start);

#endif  // __STDIO__
