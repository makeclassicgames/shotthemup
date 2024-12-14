#ifndef GAME_H
#define GAME_H

#include "ecs.h"
#include "player.h"

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
    Input lastInput;
}Game;

void initGame(Game *);
void updateGame(Game *);
void drawGame(Game *);

#endif