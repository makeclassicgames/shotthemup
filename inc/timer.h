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

#ifndef TIMER_H
#define TIMER_H

#include <raylib.h>

typedef void (*TimerCallback)(void);

typedef struct{
    long maxTime;
    long currentTime;
    bool isRunning;
    bool repeat;
    TimerCallback callback;
}Timer;

void initTimer(Timer* timer,long maxTime,TimerCallback callback,bool repeat);
void updateTimer(Timer* timer);
void startTimer(Timer* timer);
void stopTimer(Timer* timer);

#endif // TIMER_H