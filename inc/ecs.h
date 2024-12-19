#ifndef ECS_H
#define ECS_H
#include <raylib.h>

#include "physics.h"

#define MAX_ENTITIES 100

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
    PositionComponent positionComponent;
    VisibilityComponent visibilityComponent;
    TransformComponent transform;
    SpriteComponent sprite;
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



#endif