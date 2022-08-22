#ifndef MAIN_DEF
#define MAIN_DEF

#include <gb/gb.h>
#include <gb/hardware.h>
#include "../include/player_input.h"
#include "../include/render/swordsman.h"
#include "../include/swordsman_pose.h"

const unsigned char black_tile_data [] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
const unsigned char white_tile_data [] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

// TODO: separate left/right up/down so they can be calculated separately

void swordsman_state_updater(struct SwordsmanState * state)
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

struct SwordsmanState player_swordsman_state = {SP_CENTER};
struct RenderSwordsman render_swordsman_state = {SP_CENTER};

int main()
{
    set_bkg_data(0x01, 1, black_tile_data);
    set_bkg_data(0x00, 1, white_tile_data);
    SHOW_BKG;
    while(0x01)
    {
        swordsman_state_updater(&player_swordsman_state);
        render_swordsman(&render_swordsman_state, &player_swordsman_state, 5, 5);
        delay(100); 
    }
}
#endif