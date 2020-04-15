// ***************************************
//  include - event - event.h
//  Update  develop3.1
// ***************************************

#include <types.h>

#ifndef __EVENT__
#define __EVENT__

#define EVENT_BUFFER    64

//
// Event Param
//
#define EVENT_NONE          0

#define EVENT_TIMER         1

#define EVENT_KEYPRESSED    2
#define EVENT_KEYRELEASED   3

#define EVENT_MOUSEPRESSED      4
#define EVENT_MOUSERELEASED     5
#define EVENT_MOUSEMOTION       6

void initEventMan(EventMan *eman);
void putEvent(EventMan *eman, unsigned int id, unsigned long long low, unsigned long long high);
Event getEvent(EventMan *eman);

#endif  // __EVENT__
