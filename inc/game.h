#ifndef GAME_H
#define GAME_H

#include "ecs.h"
#include "player.h"
#include "timer.h"

typedef enum state{
    INITIAL,
    MENU,
    GAME_LOOP,
    GAME_OVER,
    WIN
}Status;

typedef struct{
    Scene gameScene;
    Player player;
    Status status;
    InputState lastInput;
}Game;

Game * getCurrentGame(void);
void initGame(Game * );
void updateGame(Game* );
void drawGame(Game * );

#endif