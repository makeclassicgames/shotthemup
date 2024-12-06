#include "player.h"
#include "resources.h"
#include <raylib.h>
#include "ecs.h"

void initPlayer(Player *player)
{
    player->lives = 3;
    player->score = 0;
    
    player->entity->component.pos.x=100;
    player->entity->component.pos.y=400;
    player->entity->component.visible=true;
    
    player->entity->component.sprite.texture = getSpriteTexture(SPRITE_PLAYER_1);
    player->entity->component.sprite.frameCount = 2;
    player->entity->component.sprite.animCount = 3;
    player->entity->component.sprite.frameWidth = 64;
    player->entity->component.sprite.frameHeight = 64;
    player->entity->component.sprite.currentFrame = 0;
    player->entity->component.sprite.currentAnim = 0;
}

void updatePlayer(Player* player, Input input){
        player->entity->component.speed.dy = 0;
        player->entity->component.speed.dx = 0;
    switch (input)
    {
    case UP:
        player->entity->component.speed.dy = -5;
        break;
    case DOWN:
         player->entity->component.speed.dy = 5;
        break;
    case LEFT:
         player->entity->component.speed.dx = -5;
        break;
    case RIGHT: 
        player->entity->component.speed.dy = 5;
        break;
  
    default:
        break;
    }
    
}

