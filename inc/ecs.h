#ifndef ECS_H
#define ECS_H
#include <raylib.h>

#include "physics.h"
#include "timer.h"

#define MAX_ENTITIES 100
#define MAX_TAGS 10
#define MAX_TIMERS 10

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
    PositionComponent positionComponent;
    VisibilityComponent visibilityComponent;
    TransformComponent transform;
    SpriteComponent sprite;
    TagComponent tags;
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

//Tag System
void addTag(Entity *entity, const char *tag);
void removeTag(Entity *entity, const char *tag);
bool hasTag(Entity *entity, const char *tag);
void searchByTag(ECS *ecs, const char *tag, Entity *entities, int *count);

//Timer Scene
void addTimerToScene(Scene *scene, long maxTime, TimerCallback callback, bool repeat);

#endif