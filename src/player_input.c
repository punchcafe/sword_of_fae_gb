#include "../include/player_input.h"
#include <gb/gb.h>
#ifndef PLAYER_INPUT_H
#define PLAYER_INPUT_H

// For some reason, this has tqo return an integer, otherwise it breaks
enum JoypadDirection player_input_dpad()
{
    // TODO: clear up this garbage
    unsigned char input = joypad();
    // Check none first 
    if(input == 0x00)
    {
        return JD_NONE;
    }
    if(input & J_UP)
    {
        if(input & J_LEFT)
        {
            return JD_UP_LEFT;
        } else if (input & J_RIGHT) {
            return JD_UP_RIGHT; 
        }
        return JD_UP;
    }
    if(input & J_DOWN)
    {
        if(input & J_LEFT)
        {
            return JD_DOWN_LEFT;
        } else if (input & J_RIGHT) {
            return JD_DOWN_RIGHT; 
        }
        return JD_DOWN;
    }
    if(input & J_LEFT)
    {
        return JD_LEFT;
    }
    return JD_RIGHT;
}
#endif