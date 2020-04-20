// **********************************
//  util - stdio.c
//  Update  develop3.0
// **********************************

#include <stdarg.h>

#include <types.h>

#define STDIO_BUF_LENGTH 64

int sprintf(char *s, const char *t, ...) {
    int ret = 0;
    int i, d;
    unsigned int xd;
    char num[STDIO_BUF_LENGTH], *c;
    char sx[] = {
        '0', '1', '2', '3', '4', '5', '6', '7',
        '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

    va_list ap;

    va_start(ap, t);
    do {
        switch(*t) {
        case '%':
            t++;
            switch(*t) {
            case 'd':
                i = 0;
                d = va_arg(ap, int);
                if (d < 0) {
                    *s++ = '-';
                    d = -d;
                }
                do {
                    num[i++] = (d % 10) + '0';
                } while(d /= 10);
                while(i--)
                    *s++ = num[i];
                break;

            case 'c':
                *s++ = va_arg(ap, int);
                break;

            case 'x':
                i = 0;
                xd = va_arg(ap, unsigned int);
                do {
                    num[i++] = sx[xd % 16];
                } while(xd /= 16);
                while(i--)
                    *s++ = num[i];
                break;

                /*
            case 's':
                c = va_arg(ap, char*);
                do {
                    *s++ = *c++;
                } while(*c);
                break;
                */

            default:
                *s++ = '@';
                break;
            }
            break;
        default:
            *s++ = *t;
            break;
        }
    } while(*t++);
    *s = '\0';

    va_end(ap);
    return ret;
}

