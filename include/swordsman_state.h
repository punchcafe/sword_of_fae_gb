#ifndef SWORDSMAN_STATE
#define SWORDSMAN_STATE
/*
POSE
STRIKING?
CHECKED?
TRANSITION_FRAMES_PASSED
LAST_POSE
*/
#include "./swordsman_pose.h"

struct SwordsmanState {
    enum SwordsmanPose pose;
};

#endif