#include "../../include/swordsman_state.h"
#include "../../include/player_input.h"
#include "../../include/procs/player_swordsman_state.h"

void proc_player_swordsman_state(struct SwordsmanState * state)
{
    switch(player_input_dpad())
    {
        case JD_UP:
            state->pose = SP_TOP;
            return;
        case JD_DOWN:
            state->pose = SP_BOTTOM;
            return;
        case JD_UP_LEFT:
            state->pose = SP_TOP_LEFT;
            return;
        case JD_DOWN_LEFT:
            state->pose = SP_BOTTOM_LEFT;
            return;
        case JD_LEFT:
            state->pose = SP_LEFT;
            return;
        case JD_UP_RIGHT:
            state->pose = SP_TOP_RIGHT;
            return;
        case JD_DOWN_RIGHT:
            state->pose = SP_BOTTOM_RIGHT;
            return;
        case JD_RIGHT:
            state->pose = SP_RIGHT;
            return;
        case JD_NONE:
            state->pose = SP_CENTER;
            return;
    };
}