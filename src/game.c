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
    scene->background.yoffSet++;
    scene->camera.target.y=scene->background.yoffSet;
    ECS_UpdateEntities(&scene->ecs);
    
}

void drawGameScene(Scene *scene){
    

    BeginMode2D(scene->camera);
        DrawTextureEx(scene->background.texture, (Vector2){scene->background.xoffSet,scene->background.yoffSet}, 0.0f, 2.7f, WHITE);
    EndMode2D();
    ECS_DrawEntities(&scene->ecs);
}

void initGameScene(Scene *scene, Background background){
    
    int enemyEntity_id = ECS_CreateEntity(&scene->ecs);
    scene->background.texture=background.texture;
    scene->background.xoffSet=background.xoffSet;
    scene->background.yoffSet=background.yoffSet;
    Entity enemyEntity = ECS_GetEntity(&scene->ecs,enemyEntity_id);
    enemyEntity.positionComponent.position.x=100;
    enemyEntity.positionComponent.position.y=100;
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
    int enemyEntity_id2 = ECS_CreateEntity(&scene->ecs);
    Entity enemyEntity2 = ECS_GetEntity(&scene->ecs,enemyEntity_id2);    
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

    int enemyEntity_id3 = ECS_CreateEntity(&scene->ecs);
    Entity enemyEntity3 = ECS_GetEntity(&scene->ecs,enemyEntity_id3);    
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

    //Bullet
    int bulletEntity_id = ECS_CreateEntity(&scene->ecs);
    Entity bulletEntity = ECS_GetEntity(&scene->ecs,bulletEntity_id);
    bulletEntity.positionComponent.position.x=200;
    bulletEntity.positionComponent.position.y=200;
    bulletEntity.visibilityComponent.visible=true;
    bulletEntity.sprite.texture=getSpriteTexture(SPRITE_BULLET);
    bulletEntity.sprite.frameCount=1;
    bulletEntity.sprite.animCount=1;
    bulletEntity.sprite.frameWidth=16;
    bulletEntity.sprite.frameHeight=16;
    bulletEntity.sprite.currentFrame=0;
    bulletEntity.sprite.currentAnim=0;
    bulletEntity.sprite.frameDelay=1;
    

    //init camera
    scene->camera.offset=(Vector2){0,0};
    scene->camera.target=(Vector2){scene->background.xoffSet,scene->background.xoffSet+scene->background.yoffSet};
    scene->camera.rotation=0.0f;
    scene->camera.zoom=1.0f;

    ECS_SetEntity(&scene->ecs,enemyEntity.entity_id,enemyEntity);
    ECS_SetEntity(&scene->ecs,enemyEntity2.entity_id,enemyEntity2);
    ECS_SetEntity(&scene->ecs,enemyEntity3.entity_id,enemyEntity3);
    ECS_SetEntity(&scene->ecs,bulletEntity.entity_id,bulletEntity);
}

void updateGamePlayer(Player * player, InputState input){
    Game * game = getCurrentGame();
    Entity playerEntity = ECS_GetEntity(&game->gameScene.ecs,player->entity_id);
    playerEntity.positionComponent.speed.dy = 0;
    playerEntity.positionComponent.speed.dx = 0;
    
    if(input.inputState[INPUT_DOWN]){

        playerEntity.positionComponent.speed.dy = 5;
    }
    if(input.inputState[INPUT_UP]){
        playerEntity.positionComponent.speed.dy = -5;

    }
    if(input.inputState[INPUT_LEFT]){
        playerEntity.positionComponent.speed.dx = -5;
    }
    if(input.inputState[INPUT_RIGHT]){
        playerEntity.positionComponent.speed.dx = 5;
    }

    if(input.inputState[INPUT_FIRE]){
        //fire bullet
        int bulletEntity_id = ECS_CreateEntity(&game->gameScene.ecs);
        Entity bulletEntity = ECS_GetEntity(&game->gameScene.ecs,bulletEntity_id);
        bulletEntity.positionComponent.position.x=playerEntity.positionComponent.position.x+16;
        bulletEntity.positionComponent.position.y=playerEntity.positionComponent.position.y-8;
        bulletEntity.visibilityComponent.visible=true;
        bulletEntity.sprite.texture=getSpriteTexture(SPRITE_BULLET);
        bulletEntity.sprite.frameCount=1;
        bulletEntity.sprite.animCount=1;
        bulletEntity.sprite.frameWidth=16;
        bulletEntity.sprite.frameHeight=16;
        bulletEntity.sprite.currentFrame=0;
        bulletEntity.sprite.currentAnim=0;
        bulletEntity.sprite.frameDelay=1;
        bulletEntity.positionComponent.speed.dy=-5;
        playerEntity.sprite.currentAnim=1;
        ECS_SetEntity(&game->gameScene.ecs,bulletEntity.entity_id,bulletEntity);
    }else{
        playerEntity.sprite.currentAnim=0;
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
    

    game->gameScene.init=initGameScene;
    ECS_SetEntity(&game->gameScene.ecs,game->player.entity_id,playerEntity);
    Background bg;
    bg.texture=getGfxTexture(SKY_BG);
    bg.xoffSet=0;
    bg.yoffSet=0;
    game->gameScene.init(&game->gameScene,bg);
    game->gameScene.update=updateGameScene;
    game->gameScene.draw=drawGameScene;
}

void updateGame(Game * game){

    switch (game->status)
    {
    case INITIAL:
        if(game->lastInput.inputState[INPUT_START]){
            game->status=MENU;
        }
        break;
    case MENU:
        if(game->lastInput.inputState[INPUT_START]){
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