#include "objects.h"
#include <raylib.h>

void initEnemyEntity(Entity *entity, float x,
                     float y, Texture2D texture,
                     int frameCount,
                     int animCount,
                     int frameWidth, int frameHeight, int frameDelay)
{
    entity->positionComponent.position.x = x;
    entity->positionComponent.position.y = y;
    entity->visibilityComponent.visible = true;
    entity->sprite.texture = texture;
    entity->sprite.frameCount = frameCount;
    entity->sprite.animCount = animCount;
    entity->sprite.frameWidth = frameWidth;
    entity->sprite.frameHeight = frameHeight;
    entity->sprite.currentFrame = 0;
    entity->sprite.currentAnim = 0;
    entity->sprite.frameDelay = frameDelay;
    entity->collisionComponent.xoffset = 20;
    entity->collisionComponent.yoffset = 12;
    entity->collisionComponent.width = 28;
    entity->collisionComponent.height = 43;
}

void initBulletEntity(Entity *entity, float x,
                      float y, Texture2D texture,
                      int frameCount,
                      int animCount,
                      int frameWidth, int frameHeight, int frameDelay)
{
    entity->positionComponent.position.x = x;
    entity->positionComponent.position.y = y;
    entity->visibilityComponent.visible = true;
    entity->sprite.texture = texture;
    entity->sprite.frameCount = frameCount;
    entity->sprite.animCount = animCount;
    entity->sprite.frameWidth = frameWidth;
    entity->sprite.frameHeight = frameHeight;
    entity->sprite.currentFrame = 0;
    entity->sprite.currentAnim = 0;
    entity->sprite.frameDelay = frameDelay;

    entity->collisionComponent.xoffset = 2;
    entity->collisionComponent.yoffset = 1;
    entity->collisionComponent.width = 12;
    entity->collisionComponent.height = 13;
}

void initPlayerEntity(Entity *entity, float x,
                      float y, Texture2D texture,
                      int frameCount,
                      int animCount,
                      int frameWidth, int frameHeight, int frameDelay)
{
    entity->positionComponent.position.x = x;
    entity->positionComponent.position.y = y;
    entity->visibilityComponent.visible = true;
    entity->sprite.texture = texture;
    entity->sprite.frameCount = frameCount;
    entity->sprite.animCount = animCount;
    entity->sprite.frameWidth = frameWidth;
    entity->sprite.frameHeight = frameHeight;
    entity->sprite.currentFrame = 0;
    entity->sprite.currentAnim = 0;
    entity->sprite.frameDelay = frameDelay;
    entity->transform.rotation = 0;
    entity->collisionComponent.xoffset = 18;
    entity->collisionComponent.yoffset = 5;
    entity->collisionComponent.width = 30;
    entity->collisionComponent.height = 50;

}