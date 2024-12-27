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