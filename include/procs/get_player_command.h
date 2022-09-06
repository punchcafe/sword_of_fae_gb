#ifndef GET_PLAYER_COMMAND_H
#define GET_PLAYER_COMMAND_H

#include "../swordsman_state.h"

typedef struct {
    unsigned int delay;
} GetPlayerCommandState;


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

// possibly just have an event bus if we end up with a lot of events

void get_player_command(GetPlayerCommandState * proc_state, SwordsmanState player_state, );

#endif