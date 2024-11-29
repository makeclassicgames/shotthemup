#ifndef PLAYER_H
#define PLAYER_H
#include <raylib.h>
#include "physics.h"
#include "input.h"


    typedef struct{
        Texture2D texture;
        short lives;
        long score;
        Point position;
    }Player;

    void initPlayer(Player *player);
    void updatePlayer(Player *player,Input input);
    void drawPlayer(Player *player);
#endif