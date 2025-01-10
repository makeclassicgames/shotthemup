/*
 * This file is part of Shot Them Up.
 *
 * Shot Them Up is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Shot Them Up is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Shot Them Up. If not, see <https://www.gnu.org/licenses/>.
 */

#include "timer.h"

void initTimer(Timer *timer, long maxTime, TimerCallback callback, bool repeat)
{
    timer->maxTime = maxTime;
    timer->currentTime = 0;
    timer->isRunning = false;
    timer->repeat = repeat;
    timer->callback = callback;
}

void startTimer(Timer *timer)
{
    timer->isRunning = true;
    timer->currentTime = 0;
}

void stopTimer(Timer *timer)
{
    timer->isRunning = false;
    timer->currentTime = 0;
}

void updateTimer(Timer *timer)
{
    if (timer->isRunning)
    {
        timer->currentTime++;
        if (timer->currentTime >= timer->maxTime)
        {
            timer->callback();
            if (timer->repeat)
            {
                timer->currentTime = 0;
            }
            else
            {
                timer->isRunning = false;
            }
        }
    }
}