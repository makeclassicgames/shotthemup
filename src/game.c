#include <raylib.h>
#include "ecs.h"
#include "player.h"
#include "game.h"
#include "resources.h"

static Game game;

Game * getCurrentGame(void){
    return &game;
}

void updateGameScene(Scene *scene){
   
    ECS_UpdateEntities(&scene->ecs);
    
}

void drawGameScene(Scene *scene){
    
    DrawTextureEx(getGfxTexture(SKY_BG),
                    (Vector2){0,0},
                    0.0f,2.3f,WHITE);
    ECS_DrawEntities(&scene->ecs);
}

void updateGamePlayer(Player * player, Input input){
    Game * game = getCurrentGame();
    Entity playerEntity = ECS_GetEntity(&game->gameScene.ecs,player->entity_id);
    playerEntity.positionComponent.speed.dy = 0;
    playerEntity.positionComponent.speed.dx = 0;
    switch (input)
    {
    case UP:
        playerEntity.positionComponent.speed.dy = -5;
        break;
    case DOWN:
         playerEntity.positionComponent.speed.dy = 5;
        break;
    case LEFT:
         playerEntity.positionComponent.speed.dx = -5;
        break;
    case RIGHT: 
        playerEntity.positionComponent.speed.dx = 5;
        break;
  
    default:
        break;
    }
    ECS_SetEntity(&game->gameScene.ecs,player->entity_id,playerEntity);
}

void initGame(Game* game){
    ECS_Init(&game->gameScene.ecs);

    int playerEntityId= ECS_CreateEntity(&game->gameScene.ecs);
  
    game->player.entity_id=playerEntityId;
    Entity playerEntity = ECS_GetEntity(&game->gameScene.ecs,playerEntityId);
    playerEntity.positionComponent.position.x=100;
    playerEntity.positionComponent.position.y=400;
    playerEntity.visibilityComponent.visible=true;
    
    playerEntity.sprite.texture = getSpriteTexture(SPRITE_PLAYER_1);
    playerEntity.sprite.frameCount = 2;
    playerEntity.sprite.animCount = 3;
    playerEntity.sprite.frameWidth = 64;
    playerEntity.sprite.frameHeight = 64;
    playerEntity.sprite.currentFrame = 0;
    playerEntity.sprite.currentAnim = 0;
    playerEntity.sprite.frameDelay = 5;
    initPlayer(&game->player);
    game->status=GAME_LOOP;
    game->player.update=updateGamePlayer;
    //init Entities
    

    int enemyEntity_id = ECS_CreateEntity(&game->gameScene.ecs);
    Entity enemyEntity = ECS_GetEntity(&game->gameScene.ecs,enemyEntity_id);
    enemyEntity.positionComponent.position.x=100;
    enemyEntity.positionComponent.position.y=100;
    enemyEntity.positionComponent.speed.dy=5;
    enemyEntity.visibilityComponent.visible=true;
    enemyEntity.sprite.texture=getSpriteTexture(SPRITE_ENEMY_1);
    enemyEntity.sprite.currentFrame=0;
    enemyEntity.sprite.currentAnim=0;
    enemyEntity.sprite.frameCount=2;
    enemyEntity.sprite.animCount=2;
    enemyEntity.sprite.frameWidth=64;
    enemyEntity.sprite.frameHeight=64;
    enemyEntity.sprite.frameDelay=10;

    //ENtity2
    int enemyEntity_id2 = ECS_CreateEntity(&game->gameScene.ecs);
    Entity enemyEntity2 = ECS_GetEntity(&game->gameScene.ecs,enemyEntity_id2);    
    enemyEntity2.positionComponent.position.x=160;
    enemyEntity2.positionComponent.position.y=100;
    enemyEntity2.visibilityComponent.visible=true;
    enemyEntity2.sprite.texture=getSpriteTexture(SPRITE_ENEMY_1);
    enemyEntity2.sprite.currentFrame=0;
    enemyEntity2.sprite.currentAnim=0;
    enemyEntity2.sprite.frameCount=2;
    enemyEntity2.sprite.animCount=2;
    enemyEntity2.sprite.frameWidth=64;
    enemyEntity2.sprite.frameHeight=64;
    enemyEntity2.sprite.frameDelay=10;
    //Entity3

    int enemyEntity_id3 = ECS_CreateEntity(&game->gameScene.ecs);
    Entity enemyEntity3 = ECS_GetEntity(&game->gameScene.ecs,enemyEntity_id3);    
    enemyEntity3.positionComponent.position.x=220;
    enemyEntity3.positionComponent.position.y=100;
    enemyEntity3.visibilityComponent.visible=true;
    enemyEntity3.sprite.texture=getSpriteTexture(SPRITE_ENEMY_1);
    enemyEntity3.sprite.frameCount=2;
    enemyEntity3.sprite.animCount=2;
    enemyEntity3.sprite.frameWidth=64;
    enemyEntity3.sprite.frameHeight=64;
    enemyEntity3.sprite.currentFrame=0;
    enemyEntity3.sprite.currentAnim=0;
    enemyEntity3.sprite.frameDelay=5;

    ECS_SetEntity(&game->gameScene.ecs,enemyEntity.entity_id,enemyEntity);
    ECS_SetEntity(&game->gameScene.ecs,enemyEntity2.entity_id,enemyEntity2);
    ECS_SetEntity(&game->gameScene.ecs,enemyEntity3.entity_id,enemyEntity3);
    ECS_SetEntity(&game->gameScene.ecs,game->player.entity_id,playerEntity);
    game->gameScene.update=updateGameScene;
    game->gameScene.draw=drawGameScene;
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
        game->player.update(&game->player,game->lastInput);

        game->gameScene.update(&game->gameScene);
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
        
        game->gameScene.draw(&game->gameScene);
        break;
    
    default:
        break;
    }
}