// **********************************
//  include - console - console.h
//  Update  develop3.3
// **********************************

#include <types.h>

#ifndef __CONSOLE__
#define __CONSOLE__

void initConsole(Console *cons);
void inputConsole(Console *cons, char *s);
void nLineConsole(Console *cons);
void slideConsole(Console *cons);
void clearConsole(Console *cons);
void drawConsole(Console *cons);
void printConsole(Console *cons, char *s);

#endif  // __CONSOLE__
