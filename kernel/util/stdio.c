// **********************************
//  util - stdio.c
//  Update  develop3.0
// **********************************

#include <stdarg.h>

#include <types.h>
#include <util/stdio.h>

#define STDIO_BUF_LENGTH 64

void value2str(ATYPE val, char *buf, char type, unsigned char mf, unsigned char zf, unsigned char dig) {
    const char sx[] = {
        '0', '1', '2', '3', '4', '5', '6', '7',
        '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
    unsigned int len = 0;
    char tmp[128];
    unsigned char minus = 0;

    switch(type) {
        case TYPE_UINT:
            do {
                tmp[len++] = (val.ud %10) +'0';
                if (dig > 0) dig--;
            } while (val.ud /= 10);
            break;
        case TYPE_ULLINT:
            do {
                tmp[len++] = (val.ulld %10) +'0';
                if (dig > 0) dig--;
            } while (val.ulld /= 10);
            break;
        case TYPE_SINT:
            if (val.sd < 0) {
                val.sd = -val.sd;
                minus = 1;
            }
            do {
                tmp[len++] = (val.sd %10) +'0';
                if (dig > 0) dig--;
            } while (val.sd /= 10);
            break;
        case TYPE_SLLINT:
            if (val.slld < 0) {
                val.slld = -val.slld;
                minus = 1;
            }
            do {
                tmp[len++] = (val.slld %10) +'0';
                if (dig > 0) dig--;
            } while (val.sd /= 10);
            break;
        case TYPE_UINTX:
            do {
                tmp[len++] = sx[val.ud %16];
                if (dig > 0) dig--;
            } while (val.ud /= 16);
            break;
        case TYPE_ULLINTX:
            do {
                tmp[len++] = sx[val.ulld %16];
                if (dig > 0) dig--;
            } while (val.ulld /= 16);
            break;
    }
    if (!mf) {
        if (zf) {
            // dig > 0 ???
            while(dig--) tmp[len++] = '0';
        }
        else {
            while(dig--) tmp[len++] = ' ';
        }
    }
    if (minus) {
        tmp[len++] = '-';
    }

    if (mf == 1 && len < dig)
        dig -= len;

    while (len--)
        *buf++ = tmp[len];

    if (mf) {
        while (dig--) {
            *buf++ = ' ';
        }
    }
    *buf = '\0';
}

int sprintf(char *s, const char *t, ...) {
    unsigned char len = 0, ret = 0;
    char buf[128];
    char *c;

    unsigned char mf = 0;       // minus flag
    unsigned char zf = 0;       // 0 fill
    unsigned char dig = 0;      // 0 fill digit
    unsigned char lf  = 0;      // long
    unsigned char llf = 0;      // long long

    // convert param
    ATYPE val;

    va_list ap;

    va_start(ap, t);
    do {
        if (*t == '%') {
            t++;
            // check flag
            if (*t == '-') {
                mf = 1; t++;
            }
            if (*t == '0') {
                zf = 1; t++;
            }
            if ('1' <= *t && *t <= '9') {
                dig = *t -'0'; t++;
            }
            if (*t == 'l') {
                t++;
                if (*t == 'l')  { llf = 1; t++; }
                else            {  lf = 1;      }
            }

            // convert
            if (*t == 'u') {
                if (llf) {
                    val.ulld = va_arg(ap, unsigned long long int);
                    value2str(val, buf, TYPE_ULLINT, mf, zf, dig);
                }
                else {
                    val.ud = va_arg(ap, unsigned int);
                    value2str(val, buf, TYPE_UINT, mf, zf, dig);
                }
                for (len = 0; buf[len]; len++)
                    *s++ = buf[len];
            }
            else if (*t == 'd') {
                if (llf) {
                    val.slld = va_arg(ap, signed long long int);
                    value2str(val, buf, TYPE_SLLINT, mf, zf, dig);
                }
                else {
                    val.sd = va_arg(ap, signed int);
                    value2str(val, buf, TYPE_SINT, mf, zf, dig);
                }
                for (len = 0; buf[len]; len++)
                    *s++ = buf[len];
            }
            else if (*t == 'x' || *t == 'X') {
                if (llf) {
                    val.ulld = va_arg(ap, unsigned long long int);
                    value2str(val, buf, TYPE_ULLINTX, mf, zf, dig);
                }
                else {
                    val.ud = va_arg(ap, unsigned int);
                    value2str(val, buf, TYPE_UINTX, mf, zf, dig);
                }
                for (len = 0; buf[len]; len++)
                    *s++ = buf[len];
            }
            else if (*t == 's') {
                c = va_arg(ap, char*);
                if (mf) {
                    while (dig--)
                        *s++ = ' ';
                }
                do {
                    *s++ = *c++;
                } while (*c);
                while (dig) {
                    *s++ = ' ';
                }
            }
        }
        else {
            *s++ = *t;
        }
        mf = zf = dig = lf = llf = 0;
    } while(*t++);
    *s = '\0';

    va_end(ap);
    return ret;
}

void pmem(char *s, char *start) {
    sprintf(s, "0x%08x | %02x %02x %02x %02x %02x %02x %02x %02x %02x-%02x %02x %02x%02x %02x %02x %02x",
            start, start[0], start[1], start[2], start[3], start[4], start[5], (char)(start[6] & 0xFF),
            start[7], start[8], start[9], start[10], start[11], start[12], start[13],
            start[14], start[15]);
}
