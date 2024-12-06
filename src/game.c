#include <raylib.h>
#include "ecs.h"
#include "player.h"
#include "game.h"
#include "resources.h"

void initGame(Game * game){
    ECS_Init(&game->ecs);

    Entity playerEntity = ECS_CreateEntity(&game->ecs);
  
    game->player.entity=&playerEntity;
    initPlayer(&game->player);
    game->status=GAME_LOOP;
    
    //init Entities
    

    Entity enemyEntity = ECS_CreateEntity(&game->ecs);
    enemyEntity.component.pos.x=100;
    enemyEntity.component.pos.y=100;
    enemyEntity.component.speed.dy=5;
    enemyEntity.component.visible=true;
    enemyEntity.component.sprite.texture=getSpriteTexture(SPRITE_ENEMY_1);
    enemyEntity.component.sprite.frameCount=2;
    enemyEntity.component.sprite.animCount=2;
    enemyEntity.component.sprite.frameWidth=64;
    enemyEntity.component.sprite.frameHeight=64;

    //ENtity2
    Entity enemyEntity2 = ECS_CreateEntity(&game->ecs);
    enemyEntity2.component.pos.x=160;
    enemyEntity2.component.pos.y=100;
    enemyEntity2.component.visible=true;
    enemyEntity2.component.sprite.texture=getSpriteTexture(SPRITE_ENEMY_1);
    enemyEntity2.component.sprite.frameCount=2;
    enemyEntity2.component.sprite.animCount=2;
    enemyEntity2.component.sprite.frameWidth=64;
    enemyEntity2.component.sprite.frameHeight=64;
    //Entity3

    Entity enemyEntity3 = ECS_CreateEntity(&game->ecs);
    enemyEntity3.component.pos.x=220;
    enemyEntity3.component.pos.y=100;
    enemyEntity3.component.visible=true;
    enemyEntity3.component.sprite.texture=getSpriteTexture(SPRITE_ENEMY_1);
    enemyEntity3.component.sprite.frameCount=2;
    enemyEntity3.component.sprite.animCount=2;
    enemyEntity3.component.sprite.frameWidth=64;
    enemyEntity3.component.sprite.frameHeight=64;

    ECS_SetEntity(&game->ecs,enemyEntity.entity_id,enemyEntity);
    ECS_SetEntity(&game->ecs,enemyEntity2.entity_id,enemyEntity2);
    ECS_SetEntity(&game->ecs,enemyEntity3.entity_id,enemyEntity3);
    ECS_SetEntity(&game->ecs,playerEntity.entity_id,playerEntity);
}

void updateGame(Game * game){

    switch (game->status)
    {
    case INITIAL:
        if(game->lastInput==START){
            game->status=MENU;
        }
        break;
    case MENU:
        if(game->lastInput==START){
            game->status=GAME_LOOP;
        }
    case GAME_LOOP:
        updatePlayer(&game->player,game->lastInput);
        ECS_SetEntity(&game->ecs,game->player.entity->entity_id,*game->player.entity);
        ECS_UpdateEntities(&game->ecs);
        break;
    
    default:
        break;
    }
}

void drawGame(Game* game){
    switch (game->status)
    {
    case INITIAL:
        DrawText("Initial State", 290, 200, 20, BLACK);
        break;
    case MENU:
        Texture2D texture= getGfxTexture(TITLE_SCREEN);
        DrawTexture(texture,0,0,WHITE);
        break;
    case GAME_LOOP:
        DrawText("Game Loop", 290, 200, 20, BLACK);
        
        DrawTextureEx(getGfxTexture(SKY_BG),
                    (Vector2){0,0},
                    0.0f,2.3f,WHITE);
        //DrawTexture(,0,0,WHITE);
        ECS_DrawEntities(&game->ecs);
        break;
    
    default:
        break;
    }
}