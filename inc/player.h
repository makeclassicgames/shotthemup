#ifndef PLAYER_H
#define PLAYER_H
#include <raylib.h>
#include "physics.h"
#include "ecs.h"
#include "input.h"

 typedef struct Player Player;
    
 typedef void (*updatePlayer)(Player* player, InputState input);

 typedef struct Player{
        int entity_id;
        short lives;
        long score;
        updatePlayer update;
};
   

   

    void initPlayer(Player *player);
#endif