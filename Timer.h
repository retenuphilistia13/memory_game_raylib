
#ifndef TIMER_H
#define TIMER_H

#include "raylib.h"
//#include "raymath.h"

typedef struct
{
    float Lifetime;
} Timer;

// start or restart a timer with a specific lifetime
void StartTimer(Timer* timer, float lifetime)
;

// update a timer with the current frame time
void UpdateTimer(Timer* timer)
;

// check if a timer is done.
bool TimerDone(Timer* timer)
;

#endif


