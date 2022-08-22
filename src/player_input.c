#include "../include/player_input/joypad_direction.h"
#include <gb/gb.h>

enum JoypadDirectionPress player_input_dpad()
{
    // TODO: clear up this garbage
    unsigned char input = joypad();
    // Check none first 
    if(input == 0x00)
    {
        return NONE;
    }
    if(input & J_UP)
    {
        if(input & J_LEFT)
        {
            return UP_LEFT;
        } else if (input & J_RIGHT) {
            return UP_RIGHT; 
        }
        return UP;
    }
    if(input & J_DOWN)
    {
        if(input & J_LEFT)
        {
            return DOWN_LEFT;
        } else if (input & J_RIGHT) {
            return DOWN_RIGHT; 
        }
        return DOWN;
    }
    if(input & J_LEFT)
    {
        return LEFT;
    }
    return RIGHT;
}
