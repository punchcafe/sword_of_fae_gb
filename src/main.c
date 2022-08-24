#ifndef MAIN_DEF
#define MAIN_DEF

#include <gb/gb.h>
#include <gb/hardware.h>
#include "../include/player_input.h"
#include "../include/render/swordsman.h"
#include "../include/swordsman_pose.h"
#include "../include/procs/player_swordsman_state.h"
#include "../include/procs/ai_swordsman_state.h"

const unsigned char black_tile_data [] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
const unsigned char white_tile_data [] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};


struct SwordsmanState player_swordsman_state = {SP_CENTER};
struct SwordsmanState ai_swordsman_state = {SP_CENTER};
struct RenderSwordsman render_swordsman_state = {SP_CENTER};
struct RenderSwordsman ai_render_swordsman_state = {SP_CENTER};

int main()
{
    set_bkg_data(0x01, 1, black_tile_data);
    set_bkg_data(0x00, 1, white_tile_data);
    SHOW_BKG;
    while(0x01)
    {
        proc_player_swordsman_state(&player_swordsman_state);
        proc_ai_swordsman_state(&ai_swordsman_state);
        render_swordsman(&render_swordsman_state, &player_swordsman_state, 5, 5);
        render_swordsman(&ai_render_swordsman_state, &ai_swordsman_state, 10, 5);
        delay(100); 
    }
}
#endif