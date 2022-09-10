#ifndef GET_PLAYER_COMMAND_H
#define GET_PLAYER_COMMAND_H

#include "../swordsman_state.h"
#include "../events/command_event.h"

typedef struct {
    unsigned int delay;
} GetPlayerCommandState;



// possibly just have an event bus if we end up with a lot of events

void get_player_command(GetPlayerCommandState * proc_state, struct SwordsmanState * player_state, CommandEventObservers * observers);

#endif