#ifndef OBJECTS_H
#define OBJECTS_H

#include <raylib.h>

#include "ecs.h"

void initEnemyEntity(Entity *entity, float x,
                     float y, Texture2D texture,
                     int frameCount,
                     int animCount,
                     int frameWidth, int frameHeight, int frameDelay);

void initBulletEntity(Entity *entity, float x,
                      float y, Texture2D texture,
                      int frameCount,
                      int animCount,
                      int frameWidth, int frameHeight, int frameDelay);

void initPlayerEntity(Entity *entity, float x,
                      float y, Texture2D texture,
                      int frameCount,
                      int animCount,
                      int frameWidth, int frameHeight, int frameDelay);
#endif // OBJECTS_H