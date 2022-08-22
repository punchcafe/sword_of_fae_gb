#include "../../include/swordsman_state.h"
#include "../../include/render/swordsman.h"
#include <gb/gb.h>

const unsigned char tile_array_black [] = {0x01};
const unsigned char tile_array_none [] = {0x00};

int _render_swordsman_x_offset(enum SwordsmanPose pose)
{
    if(pose == SP_LEFT || pose == SP_TOP_LEFT || pose == SP_BOTTOM_LEFT)
    {
        return -1;
    } else if(pose == SP_RIGHT || pose == SP_TOP_RIGHT || pose == SP_BOTTOM_RIGHT){
        return 1;
    }
    return 0;
}

int _render_swordsman_y_offset(enum SwordsmanPose pose)
{
    if(pose == SP_TOP || pose == SP_TOP_LEFT || pose == SP_TOP_RIGHT)
    {
        return -1;
    } else if(pose == SP_BOTTOM || pose == SP_BOTTOM_LEFT || pose == SP_BOTTOM_RIGHT){
        return 1;
    }
    return 0;
}

void render_swordsman(struct RenderSwordsman * render_state, 
                      struct SwordsmanState * state, 
                      int x, 
                      int y){
    int last_pose_x = _render_swordsman_x_offset(render_state->last_pose) + x;
    int last_pose_y = _render_swordsman_y_offset(render_state->last_pose) + y;
    set_bkg_tiles(last_pose_x, last_pose_y, 1, 1, tile_array_none);
    int x_offset = _render_swordsman_x_offset(state->pose) + x;
    int y_offset = _render_swordsman_y_offset (state->pose) + y;
    set_bkg_tiles(x_offset, y_offset, 1, 1, tile_array_black);
    render_state->last_pose = state->pose;
}