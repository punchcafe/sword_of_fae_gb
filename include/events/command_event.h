
#ifndef COMMAND_EVENT_H
#define COMMAND_EVENT_H

#include "../observer.h"

typedef enum {
    MOVE_GUARD
    // BLOCK
    // CUT-THROUGH
    // STAB
    // NONE
} CommandEventType;

typedef struct {
    CommandEventType type;
    void * body;
} CommandEvent;

GENERATE_OBSERVERS(CommandEvent, command_event)
#endif