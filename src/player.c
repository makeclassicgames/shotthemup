#include "player.h"
#include <raylib.h>

void initPlayer(Player *player)
{
    player->lives = 3;
    player->score = 0;
    player->position.x = 400;
    player->position.y = 400;
}

void updatePlayer(Player* player, Input input){
    switch (input)
    {
    case UP:
        player->position.y -= 5;
        break;
    case DOWN:
        player->position.y += 5;
        break;
    case LEFT:
        player->position.x -= 5;
        break;
    case RIGHT: 
        player->position.x += 5;
        break;
    default:
        break;
    }
}

void drawPlayer(Player *player){
    DrawRectangle(player->position.x,
     player->position.y,
     20, 20, RED);
}