#ifndef ECS_H
#define ECS_H
#include <raylib.h>

#include "physics.h"

#define MAX_ENTITIES 100

typedef struct{
    Texture2D texture;
    int frameCount;
    int animCount;
    int frameWidth;
    int frameHeight;
    int currentFrame;
    int currentAnim;
}Sprite;

typedef struct{
    Point pos;
    Speed speed;
    bool visible;
    Transform transform;
    Sprite sprite;
}Component;

typedef struct{
    Component component;
    int entity_id;
}Entity;

typedef struct{
    Entity entities[MAX_ENTITIES];
    int count;
}ECS;

void ECS_Init(ECS *ecs);
Entity ECS_CreateEntity(ECS *ecs);
void ECS_DestroyEntity(ECS *ecs, int entity_id);
void ECS_UpdateEntities(ECS *ecs);
void ECS_DrawEntities(ECS *ecs);
Entity ECS_GetEntity(ECS *ecs, int entity_id);
void ECS_SetEntity(ECS *ecs, int entity_id, Entity entity);

#endif