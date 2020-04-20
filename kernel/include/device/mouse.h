// ***************************************
//  include - device - mouse
//  Update  develop3.4
// ***************************************

#include <types.h>

#ifndef __DEVICE_MOUSE__
#define __DEVICE_MOUSE__

#define MOUSE_LBUTTON   0x01
#define MOUSE_RBUTTON   0x02
#define MOUSE_CBUTTON   0x04
#define MOUSE_BUTTONUP  0x08

extern GraphicInfo *gInfo;

void initMouseInfo(MouseInfo *mi);
void inputMouseInfo(MouseInfo *mi, char data);
int  decodeMouseInfo(MouseInfo *mi);
void drawMouse(MouseInfo *mi);

#endif  // __DEVICE_MOUSE__
