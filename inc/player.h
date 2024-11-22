#ifndef PLAYER_H
#define PLAYER_H
#include "physics.h"
#include "input.h"


    typedef struct{
        short lives;
        long score;
        Point position;
    }Player;

    void initPlayer(Player *player);
    void updatePlayer(Player *player,Input input);
    void drawPlayer(Player *player);
#endif