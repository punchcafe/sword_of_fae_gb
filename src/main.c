#ifndef MAIN_DEF
#define MAIN_DEF

#include<gb/gb.h>
#include<gb/hardware.h>

const unsigned char black_tile_data [] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
const unsigned char white_tile_data [] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

enum JoypadDirectionPress {
    UP, UP_RIGHT, RIGHT, DOWN_RIGHT, DOWN, DOWN_LEFT, LEFT, UP_LEFT, NONE
};

enum JoypadDirectionPress player_input_direction()
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

// TODO: separate left/right up/down so they can be calculated separately


unsigned short player_input_direction_x(enum JoypadDirectionPress player_input_direction)
{
    switch(player_input_direction)
    {
        case UP:
            return 5;
        case DOWN:
            return 5;
        case UP_LEFT:
            return 4;
        case DOWN_LEFT:
            return 4;
        case LEFT:
            return 4;
        case UP_RIGHT:
            return 6;
        case DOWN_RIGHT:
            return 6;
        case RIGHT:
            return 6;
        case NONE:
            return 5;
    }
    return 5;
}

unsigned short player_input_direction_y(enum JoypadDirectionPress player_input_direction)
{
    switch(player_input_direction)
    {
        case UP:
            return 4;
        case DOWN:
            return 6;
        case UP_LEFT:
            return 4;
        case DOWN_LEFT:
            return 6;
        case LEFT:
            return 5;
        case UP_RIGHT:
            return 4;
        case DOWN_RIGHT:
            return 6;
        case RIGHT:
            return 5;
        case NONE:
            return 5;
    }
    return 5;
}

int main()
{
    set_bkg_data(0x01, 1, black_tile_data);
    set_bkg_data(0x00, 1, white_tile_data);
    const unsigned char tile_array_black [] = {0x01};
    const unsigned char tile_array_none [] = {0x00};
    set_bkg_tiles(5, 5, 1, 1, tile_array_black);
    enum JoypadDirectionPress last_direction_pressed = NONE;
    SHOW_BKG;
    while(0x01)
    {
        set_bkg_tiles(player_input_direction_x(last_direction_pressed), player_input_direction_y(last_direction_pressed), 1, 1, tile_array_none); 
        last_direction_pressed = player_input_direction();
        set_bkg_tiles(player_input_direction_x(last_direction_pressed), player_input_direction_y(last_direction_pressed), 1, 1, tile_array_black);
        delay(100); 
    }
    return 0;
}
#endif