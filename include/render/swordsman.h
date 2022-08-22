#ifndef REDNER_SWORDSMAN
#define REDNER_SWORDSMAN

#include "../swordsman_state.h"

struct RenderSwordsman {
    enum SwordsmanPose last_pose;
};

void render_swordsman(struct RenderSwordsman * render_state, 
                      struct SwordsmanState * state, 
                      int x, 
                      int y);

#endif