// **************************************
//  include - util - asmfunc.h
//  Update  develop3.0
// **************************************

#include <types.h>

#ifndef __ASMFUNC__
#define __ASMFUNC__

extern void io_cli(void);
extern void io_sti(void);
extern char io_in8(unsigned short int port);
extern int  io_in32(unsigned int port);
extern void io_out8(unsigned short int port, unsigned char data);
extern void io_out32(unsigned short int port, unsigned int data);

#endif  // __ASMFUNC__
