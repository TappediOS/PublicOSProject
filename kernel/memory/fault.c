// ***************************************
//  memory - fault.c
//  Update  develop4.0
// ***************************************

#include <types.h>
#include <util/asmfunc.h>
#include <console/console.h>

extern Console console;

void emptyHandler(void) {
    printConsole(&console, "empty Handler\n");
    while (1) {
        io_cli();
        io_hlt();
    }
}

void deHandler(void) {
    printConsole(&console, "divide 0 error!");
    while(1) {
        io_cli();
        io_hlt();
    }
}

void dbHandler(void) {
    printConsole(&console, "debug error!");
    while (1) {
        io_cli();
        io_hlt();
    }
}

void nmiHandler(void) {
    printConsole(&console, "NMI ERROR!");
    while (1) {
        io_cli();
        io_hlt();
    }
}

void bpHandler(void) {
    printConsole(&console, "break point error");
    while (1) {
        io_cli();
        io_hlt();
    }
}

void ofHandler(void) {
    printConsole(&console, "over flow");
    while (1) {
        io_cli();
        io_hlt();
    }
}

void brHandler(void) {
    printConsole(&console, "bound out of range");
    while (1) {
        io_cli();
        io_hlt();
    }
}

void udHandler(void) {
    printConsole(&console, "undefined opcode");
    while (1) {
        io_cli();
        io_hlt();
    }
}

void nmHandler(void) {
    printConsole(&console, "device unuseable");
    while (1) {
        io_cli();
        io_hlt();
    }
}

void dfHandler(void) {
    printConsole(&console, "double fault");
    while (1) {
        io_cli();
        io_hlt();
    }
}


void tsHandler(void) {
    printConsole(&console, "invalid task switch");
    while (1) {
        io_cli();
        io_hlt();
    }
}

void npHandler(void) {
    printConsole(&console, "invalid segment");
    while (1) {
        io_cli();
        io_hlt();
    }
}

void ssHandler(void) {
    printConsole(&console, "stack segment fault");
    while (1) {
        io_cli();
        io_hlt();
    }
}

void gpHandler(void) {
    printConsole(&console, "general protection");
    while (1) {
        io_cli();
        io_hlt();
    }
}

void pfHandler(void) {
    printConsole(&console, "page fault");
    while (1) {
        io_cli();
        io_hlt();
    }
}

void mfHandler(void) {
    printConsole(&console, "coprocessor segment overrun");
    while (1) {
        io_cli();
        io_hlt();
    }
}

void acHandler(void) {
    printConsole(&console, "alignment check exception");
    while (1) {
        io_cli();
        io_hlt();
    }
}

void mcHandler(void) {
    printConsole(&console, "machine check exception");
    while (1) {
        io_cli();
        io_hlt();
    }
}

void xmHandler(void) {
    printConsole(&console, "floting point exception");
    while (1) {
        io_cli();
        io_hlt();
    }
}


