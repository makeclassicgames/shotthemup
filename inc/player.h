#ifndef PLAYER_H
#define PLAYER_H
#include <raylib.h>
#include "physics.h"
#include "ecs.h"
#include "input.h"


    typedef struct{
        Entity * entity;
        short lives;
        long score;
    }Player;

    void initPlayer(Player *player);
    void updatePlayer(Player *player,Input input);
#endif