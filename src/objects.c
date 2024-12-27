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
    addTag(entity, "bullet");
}