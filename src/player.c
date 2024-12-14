#include "player.h"
#include "resources.h"
#include <raylib.h>
#include "ecs.h"

void initPlayer(Player *player)
{
    player->lives = 3;
    player->score = 0;
    
    
}

void updatePlayer(Player* player, Input input){
    player->entity->positionComponent.speed.dy = 0;
    player->entity->positionComponent.speed.dx = 0;
    switch (input)
    {
    case UP:
        player->entity->positionComponent.speed.dy = -5;
        break;
    case DOWN:
         player->entity->positionComponent.speed.dy = 5;
        break;
    case LEFT:
         player->entity->positionComponent.speed.dx = -5;
        break;
    case RIGHT: 
        player->entity->positionComponent.speed.dy = 5;
        break;
  
    default:
        break;
    }
    
}

