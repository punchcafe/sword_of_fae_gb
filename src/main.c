#ifndef MAIN_DEF
#define MAIN_DEF

#include <gb/gb.h>
#include <gb/hardware.h>
#include "../include/player_input.h"
#include "../include/render/swordsman.h"
#include "../include/swordsman_pose.h"
#include "../include/procs/get_player_command.h"
#include "../include/procs/ai_swordsman_state.h"
#include "../include/procs/player_swordsman_state.h"

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
/*

notes

void update_player_command(proc_state, player_state, current_command, observers);
// Looks at player state, if and converts to top-level commands like:
cut-through
none
move-guard
{block, :left}
The abstraction at this stage is clearly:
take user inputs, and convert them into abstracted 'commands'
// or alternatively have observer 
void update_player_state(player_state, command_state);


listing commands:
none
move-guard
block
cut-through
stab

Separete all things into two categories:
callbacks and processes.
Callbacks are a perfectly valid way to update state
use callbacks when needed, and processes can assume reliance on callbacks

example module:

void player_state_on_command(Command ..., required_params )

void duelist_state_on_attack_event(... event (including target))
... sets player state as attacking
... awaits an on_attack_response callback to inform it that it's attack is finished
AttackCommand -> intention to attack
AttackEvent -> attack event which must be responded to

// CONSIDER animation lock.
// Consider a global set of locks which a process (animation etc) can claim until finishing
*/
#endif