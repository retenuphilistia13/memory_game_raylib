/*
 * Timer.cpp
 *
 *  Created on: Sep 24, 2023
 *      Author: ahmed
 */
#include"Timer.h"
// start or restart a timer with a specific lifetime
void StartTimer(Timer* timer, float lifetime)
{
    if (timer != nullptr)
        timer->Lifetime = lifetime;
}

// update a timer with the current frame time
void UpdateTimer(Timer* timer)
{
    // subtract this frame from the timer if it's not allready expired
    if (timer != nullptr && timer->Lifetime > 0)
        timer->Lifetime -= GetFrameTime();
}

// check if a timer is done.
bool TimerDone(Timer* timer)
{
    if (timer != nullptr)
        return timer->Lifetime <= 0;

	return false;
}



