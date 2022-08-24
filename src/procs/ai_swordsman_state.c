#include "../../include/swordsman_state.h"
#include "../../include/procs/ai_swordsman_state.h"

// TODO: separate into stateless context
unsigned int time_buffer = 0;
enum SwordsmanPosition position = SP_CENTER;


void proc_ai_swordsman_state(struct SwordsmanState * state)
{
    time_buffer++;
    if(time_buffer > 5)
    {
        position = (position + 1) % 9;
        state->pose = position;
        time_buffer = 0;
    }
}