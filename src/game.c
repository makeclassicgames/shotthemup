/*
 * This file is part of Shot Them Up.
 *
 * Shot Them Up is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Shot Them Up is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Shot Them Up. If not, see <https://www.gnu.org/licenses/>.
 */

#include <raylib.h>
#include <stdlib.h>
#include <stdio.h>
#include "ecs.h"
#include "player.h"
#include "objects.h"
#include "game.h"
#include "resources.h"

static Game game;

Game *getCurrentGame(void)
{
    return &game;
}

void finishFireAnimation()
{
    Game *game = getCurrentGame();
    Entity playerEntity = ECS_GetEntity(&game->gameScene.ecs, game->player.entity_id);
    playerEntity.sprite.currentAnim = 0;
    ECS_SetEntity(&game->gameScene.ecs, game->player.entity_id, playerEntity);
}

void finishDeathAnimation()
{
    Game *game = getCurrentGame();
    Entity enemies[10];
    int count = 0;
    searchByTag(&game->gameScene.ecs, "enemy", enemies, &count);
    for (int i = 0; i < count; i++)
    {
        if (enemies[i].sprite.currentAnim == 3 && enemies[i].sprite.currentFrame == enemies[i].sprite.frameCount - 1)
        {
            ECS_DestroyEntity(&game->gameScene.ecs, enemies[i].entity_id);
        }
    }
}

void updateGameScene(Scene *scene)
{

    if (scene->background.yoffSet > GetScreenHeight() - scene->background.texture.height)
    {
        scene->background.yoffSet--;
    }

    scene->camera.target.y = scene->background.yoffSet;

    // update enemies position using tags
    Entity enemies[MAX_ENTITIES];
    Entity bullets[MAX_ENTITIES];
    int bulletCount = 0;
    int count = 0;

    searchByTag(&scene->ecs, "enemy", enemies, &count);
    searchByTag(&scene->ecs, "bullet", bullets, &bulletCount);

    for (int i = 0; i < count; i++)
    {
        enemies[i].positionComponent.speed.dy = 3.0f;
        for (int j = 0; j < bulletCount; j++)
        {
            if (ECS_EntityIsColliding(&enemies[i], &bullets[j]))
            {
                enemies[i].sprite.currentAnim = 3;
                startTimer(&scene->timers[2]);
            }else{
                if(enemies[i].positionComponent.position.y > GetScreenHeight()){
                    ECS_DestroyEntity(&scene->ecs, enemies[i].entity_id);
                }
                if(bullets[j].positionComponent.position.y < -16){
                    ECS_DestroyEntity(&scene->ecs, bullets[j].entity_id);
                }else{
                    if(bullets[j].positionComponent.position.y > GetScreenHeight()){
                        ECS_DestroyEntity(&scene->ecs, bullets[j].entity_id);
                    }
                }
            }


        }
        ECS_SetEntity(&scene->ecs, enemies[i].entity_id, enemies[i]);
    }

   

    ECS_UpdateEntities(&scene->ecs);
}

void drawGameScene(Scene *scene)
{

    BeginMode2D(scene->camera);
    DrawTextureEx(scene->background.texture, (Vector2){scene->background.rect.x, scene->background.rect.y}, 0.0f, 1.0f, WHITE);
    EndMode2D();
    ECS_DrawEntities(&scene->ecs);
}

void initGameScene(Scene *scene, Background background)
{

    int enemyEntity_id = ECS_CreateEntity(&scene->ecs);
    scene->background.texture = background.texture;
    scene->background.xoffSet = background.xoffSet;
    scene->background.yoffSet = background.yoffSet;
    scene->background.rect = background.rect;
    Entity enemyEntity = ECS_GetEntity(&scene->ecs, enemyEntity_id);
    initEnemyEntity(&enemyEntity, 100, 100, getSpriteTexture(SPRITE_ENEMY_1), 2, 2, 64, 64, 10);

    addTag(&enemyEntity, "enemy");

    // ENtity2
    int enemyEntity_id2 = ECS_CreateEntity(&scene->ecs);
    Entity enemyEntity2 = ECS_GetEntity(&scene->ecs, enemyEntity_id2);
    initEnemyEntity(&enemyEntity2, 200, 100, getSpriteTexture(SPRITE_ENEMY_1), 2, 2, 64, 64, 10);
    addTag(&enemyEntity2, "enemy");
    // Entity3

    int enemyEntity_id3 = ECS_CreateEntity(&scene->ecs);
    Entity enemyEntity3 = ECS_GetEntity(&scene->ecs, enemyEntity_id3);
    initEnemyEntity(&enemyEntity3, 300, 100, getSpriteTexture(SPRITE_ENEMY_1), 2, 2, 64, 64, 10);
    addTag(&enemyEntity3, "enemy");

    // init camera
    scene->camera.offset = (Vector2){0, 0};
    scene->camera.target = (Vector2){scene->background.xoffSet, scene->background.xoffSet + scene->background.yoffSet};
    scene->camera.rotation = 0.0f;
    scene->camera.zoom = 1.0f;

    scene->timerCount = 0;

    ECS_SetEntity(&scene->ecs, enemyEntity.entity_id, enemyEntity);
    ECS_SetEntity(&scene->ecs, enemyEntity2.entity_id, enemyEntity2);
    ECS_SetEntity(&scene->ecs, enemyEntity3.entity_id, enemyEntity3);
}

void updateGamePlayer(Player *player, InputState input)
{
    Game *game = getCurrentGame();
    Entity playerEntity = ECS_GetEntity(&game->gameScene.ecs, player->entity_id);
    playerEntity.positionComponent.speed.dy = 0;
    playerEntity.positionComponent.speed.dx = 0;

    if (input.inputState[INPUT_DOWN] &&
        playerEntity.positionComponent.position.y < GetScreenHeight() - playerEntity.sprite.frameHeight)
    {

        playerEntity.positionComponent.speed.dy = 5;
    }
    if (input.inputState[INPUT_UP] &&
        playerEntity.positionComponent.position.y > 0)
    {
        playerEntity.positionComponent.speed.dy = -5;
    }
    if (input.inputState[INPUT_LEFT] &&
        playerEntity.positionComponent.position.x > 0)
    {
        playerEntity.positionComponent.speed.dx = -5;
    }
    if (input.inputState[INPUT_RIGHT] &&
        playerEntity.positionComponent.position.x < GetScreenWidth() - playerEntity.sprite.frameWidth)
    {
        playerEntity.positionComponent.speed.dx = 5;
    }

    if (input.inputState[INPUT_FIRE])
    {
        // fire bullet
        int bulletEntity_id = ECS_CreateEntity(&game->gameScene.ecs);
        Entity bulletEntity = ECS_GetEntity(&game->gameScene.ecs, bulletEntity_id);
        initBulletEntity(&bulletEntity, playerEntity.positionComponent.position.x + 16, playerEntity.positionComponent.position.y - 8, getSpriteTexture(SPRITE_BULLET), 1, 1, 16, 16, 5);
        bulletEntity.positionComponent.speed.dy = -5;
        addTag(&bulletEntity, "bullet");
        playerEntity.sprite.currentAnim = 1;
        addProperty(&bulletEntity, "damage", 1);
        ECS_SetEntity(&game->gameScene.ecs, bulletEntity.entity_id, bulletEntity);
        startTimer(&game->gameScene.timers[1]);
    }
    ECS_SetEntity(&game->gameScene.ecs, player->entity_id, playerEntity);
}

void timerFunct(void)
{
    Game *game = getCurrentGame();
    Scene *scene = &game->gameScene;
    int enemyEntity_id3 = ECS_CreateEntity(&scene->ecs);
    Entity enemyEntity3 = ECS_GetEntity(&scene->ecs, enemyEntity_id3);
    initEnemyEntity(&enemyEntity3, rand() % GetScreenWidth(), -64,
                    getSpriteTexture(SPRITE_ENEMY_1), 2, 2, 64, 64, 10);
    enemyEntity3.positionComponent.speed.dy = 2;
    ECS_SetEntity(&game->gameScene.ecs, enemyEntity_id3, enemyEntity3);
}

void initGame(Game *game)
{
    ECS_Init(&game->gameScene.ecs);

    int playerEntityId = ECS_CreateEntity(&game->gameScene.ecs);

    game->player.entity_id = playerEntityId;
    Entity playerEntity = ECS_GetEntity(&game->gameScene.ecs, playerEntityId);
    initPlayerEntity(&playerEntity, 100, 400, getSpriteTexture(SPRITE_PLAYER_1), 2, 3, 64, 64, 5);
    addTag(&playerEntity, "player");
    initPlayer(&game->player);
    game->status = GAME_LOOP;
    game->player.update = updateGamePlayer;
    // init Entities

    game->gameScene.init = initGameScene;
    ECS_SetEntity(&game->gameScene.ecs, game->player.entity_id, playerEntity);
    Background bg;
    bg.texture = getGfxTexture(SKY_BG);
    bg.xoffSet = 0;
    bg.yoffSet = 0;
    bg.rect = (Rectangle){-GetScreenWidth() / 9, GetScreenHeight() - bg.texture.height, bg.texture.width, bg.texture.height};
    game->gameScene.init(&game->gameScene, bg);
    game->gameScene.update = updateGameScene;
    game->gameScene.draw = drawGameScene;
    addTimerToScene(&game->gameScene, 120, timerFunct, true);
    addTimerToScene(&game->gameScene, 6, finishFireAnimation, false);
    addTimerToScene(&game->gameScene, 6, finishDeathAnimation, false);
    startTimer(&game->gameScene.timers[0]);
}