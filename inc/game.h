#ifndef GAME_H
#define GAME_H

#include "player.h"
typedef struct{
    Player player;
}Game;

void initGame(Game *game);
void updateGame(Game *game);
void drawGame(Game *game);

#endif