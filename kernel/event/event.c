// ***************************************
//  event - event.c
//  Update  develop3.1
// ***************************************

#include <types.h>
#include <event/event.h>

void initEvent(EventMan *eman) {
    unsigned int i;
    for (i = 0; i < EVENT_BUFFER; i++) {
        eman->event[i].id   = EVENT_NONE;
        eman->event[i].low  = 0;
        eman->event[i].high = 0;
    }
    eman->read  = 0;
    eman->write = 0;
}

void putEvent(EventMan *eman, unsigned int id, unsigned long long low, unsigned long long high) {
    eman->write = (eman->write + 1) % EVENT_BUFFER;
    eman->event[eman->write].id     = id;
    eman->event[eman->write].low    = low;
    eman->event[eman->write].high   = high;
}

Event getEvent(EventMan *eman) {
    Event event = {0, 0, 0};
    if (eman->read == eman->write)
        return event;
    else {
        eman->read = (eman->read + 1) % EVENT_BUFFER;
        return eman->event[eman->read];
    }
}

