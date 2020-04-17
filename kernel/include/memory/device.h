// ************************************
//  include - memory - device.h
//  Update  develop3.0
// ************************************

#include <types.h>

#ifndef __DEVICE__
#define __DEVICE__

// timer
void initTimer(void);

// keyboard
void initKeyBoard(void);
void waitKeyboardSendReady(void);

// mouse
void initMouse(void);

#endif  // __DEVICE__