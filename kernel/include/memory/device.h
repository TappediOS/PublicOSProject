// ************************************
//  include - memory - device.h
//  Update  develop3.0
// ************************************

#include <types.h>

#ifndef __DEVICE__
#define __DEVICE__

#define PIT_CTRL    0x0043
#define PIT_CNT0    0x0040

// timer
void initTimer(void);

// keyboard
void initKeyBoard(void);
void waitKeyboardSendReady(void);

// mouse
void initMouse(void);

#endif  // __DEVICE__
