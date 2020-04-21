// **************************************
//  console - console.c
//  Update  develop3.3
// **************************************

#include <console/console.h>
#include <graphic/graphic.h>

void initConsole(Console *cons) {
    unsigned int i;
    for (i = 0; i < CONSOLE_ROW * CONSOLE_LINE; i++)
        cons->buf[i] = '\0';
    cons->ptr = 0;
}

void inputConsole(Console *cons, char *s) {
    while (*s) {
        if (*s == '\n') {
            nLineConsole(cons);
            s++;
        }
        if (cons->ptr / CONSOLE_ROW == CONSOLE_LINE) {
            slideConsole(cons);
        }
        cons->buf[cons->ptr++] = *s;
        s++;
    }
    nLineConsole(cons);
}

void nLineConsole(Console *cons) {
    do {
        cons->buf[cons->ptr] = '\0';
    } while(cons->ptr++ % CONSOLE_ROW != (CONSOLE_ROW - 1));
}

void slideConsole(Console *cons) {
    unsigned int line, row;
    for (line = 1; line < CONSOLE_LINE; line++) {
        for (row = 0; row < CONSOLE_ROW; row++) {
            cons->buf[(line-1) * CONSOLE_ROW + row] = cons->buf[line * CONSOLE_ROW + row];
        }
    }
    for (row = 0; row < CONSOLE_ROW; row++) {
        cons->buf[(CONSOLE_LINE - 1) * CONSOLE_ROW + row] = '\0';
    }

    cons->ptr = (CONSOLE_LINE - 1) * CONSOLE_ROW;
}

void clearConsole(Console *cons) {
    initConsole(cons);
}

void drawConsole(Console *cons) {
    const int sx = 10, sy = 20;

    drawRectangle(sx + 1, sy + 1, CONSOLE_ROW * 8, CONSOLE_LINE * 16, 0x000000);

    unsigned int line, row;
    char ch;
    for (line = 0; line < CONSOLE_LINE; line++) {
        for (row = 0; row < CONSOLE_ROW; row++) {
            ch = cons->buf[line * CONSOLE_ROW + row];
            if (ch)
                drawCharacter(sx + row * 8, sy + line * 16, ch, 0xFFFFFF);
        }
    }
}




