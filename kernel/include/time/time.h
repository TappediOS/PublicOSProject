// *********************************
//  include - device - time.h
//  Update  develop3.5
// *********************************

#include <types.h>

#ifndef __dTIME__
#define __dTIME__       // __TIME__は使えない

int updateRtc();

Time getTime(void);
unsigned char getTimeData(int addr);
unsigned char changeTimeData(char data);

#endif  // __dTIME__
