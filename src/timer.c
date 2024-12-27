#include "timer.h"

void initTimer(Timer* timer,long maxTime,TimerCallback callback,bool repeat){
    timer->maxTime=maxTime;
    timer->currentTime=0;
    timer->isRunning=false;
    timer->repeat=repeat;
    timer->callback=callback;
}

void startTimer(Timer* timer){
    timer->isRunning=true;
    timer->currentTime=0;
}

void stopTimer(Timer* timer){
    timer->isRunning=false;
    timer->currentTime=0;
}

void updateTimer(Timer* timer){
    if(timer->isRunning){
        timer->currentTime++;
        if(timer->currentTime>=timer->maxTime){
            timer->callback();
            if(timer->repeat){
                timer->currentTime=0;
            }else{
                timer->isRunning=false;
            }
        }
    }
}