/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef ECS_H
#define ECS_H

/**
 * @file
 * @brief ECS System Definition
 */

#include <raylib.h>

#include "properties.h"
#include "physics.h"
#include "timer.h"

//MAX values for ECS
#define MAX_ENTITIES 100
//MAX Tags for an entity
#define MAX_TAGS 10
//MAX Timers for a scene
#define MAX_TIMERS 10
//MAX Properties for an entity
#define MAX_PROPERTIES 50



typedef struct{
    Texture2D texture;
    int xoffSet;
    int yoffSet;
    Rectangle rect;
}Background;




typedef Transformation TransformComponent;

typedef struct{
    Texture2D texture;
    int frameCount;
    int animCount;
    int frameWidth;
    int frameHeight;
    int currentFrame;
    int currentAnim;
    int frameDelay;
}SpriteComponent;

typedef struct{
    Point position;
    Speed speed;
}PositionComponent;

typedef struct{
    bool visible;
}VisibilityComponent;

typedef struct{
    char tag[MAX_TAGS][30];
    int tagCount;
}TagComponent;

typedef struct{
    KeyValue properties[MAX_PROPERTIES];
    int propertyCount;
}PropertyComponent;


typedef struct{
    PositionComponent positionComponent;
    VisibilityComponent visibilityComponent;
    TransformComponent transform;
    SpriteComponent sprite;
    TagComponent tags;
    Collider collisionComponent;
    PropertyComponent properties;
    int entity_id;
}Entity;

typedef struct{
    Entity entities[MAX_ENTITIES];
    int count;
    int ecs_delta;
}ECS;

typedef struct Scene Scene;

typedef void (*updateScene)(Scene *self);
typedef void (*drawScene)(Scene *self);
typedef void (*initScene)(Scene *self, Background Background);

typedef struct Scene{
    Background background;
    Camera2D camera;
    ECS ecs;
    Timer timers[MAX_TIMERS];
    int timerCount;
    initScene init;
    updateScene update;
    drawScene draw;
};




void ECS_Init(ECS *ecs);
int ECS_CreateEntity(ECS *ecs);
void ECS_DestroyEntity(ECS *ecs, int entity_id);
void ECS_UpdateEntities(ECS *ecs);
void ECS_DrawEntities(ECS *ecs);
Entity ECS_GetEntity(ECS *ecs, int entity_id);
void ECS_SetEntity(ECS *ecs, int entity_id, Entity entity);
bool ECS_EntityIsColliding(Entity *entity1, Entity *entity2);

//Tag System
void addTag(Entity *entity, const char *tag);
void removeTag(Entity *entity, const char *tag);
bool hasTag(Entity *entity, const char *tag);
void searchByTag(ECS *ecs, const char *tag, Entity *entities, int *count);

//Timer Scene
void addTimerToScene(Scene *scene, long maxTime, TimerCallback callback, bool repeat);
void updateTimers(Scene *scene);

//Properties System

void addProperty(Entity *entity, const char *key, PropertyValue value);
void removeProperty(Entity *entity, const char *key);
void getProperty(Entity *entity, const char *key, PropertyValue *value);
#endif