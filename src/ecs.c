#include "ecs.h"

static int next_entity_id = 0;


void ECS_Init(ECS *ecs)
{
    ecs->count = 0;
    ecs->ecs_delta = 0;
}

int ECS_CreateEntity(ECS *ecs)
{
    Entity entity;
    entity.entity_id = next_entity_id;
    next_entity_id++;
    ecs->entities[ecs->count] = entity;
    ecs->count++;
    return entity.entity_id;
}

Entity ECS_GetEntity(ECS *ecs, int entity_id)
{
    for (int i = 0; i < ecs->count; i++)
    {
        if (ecs->entities[i].entity_id == entity_id)
        {
            return ecs->entities[i];
        }
    }
    Entity entity;
    entity.entity_id = -1;
    return entity;
}

void ECS_SetEntity(ECS *ecs, int entity_id, Entity entity)
{
    for (int i = 0; i < ecs->count; i++)
    {
        if (ecs->entities[i].entity_id == entity_id)
        {
            ecs->entities[i] = entity;
        }
    }
}

void ECS_DestroyEntity(ECS *ecs, int entity_id)
{
    for (int i = 0; i < ecs->count; i++)
    {
        if (ecs->entities[i].entity_id == entity_id)
        {
            for (int j = i; j < ecs->count - 1; j++)
            {
                ecs->entities[j] = ecs->entities[j + 1];
            }
            ecs->count--;
        }
    }
}

void ECS_UpdateEntities(ECS *ecs)
{
    ecs->ecs_delta++;
    for (int i = 0; i < ecs->count; i++)
    {
        // update Position
        ecs->entities[i].positionComponent.position.x += ecs->entities[i].positionComponent.speed.dx;
        ecs->entities[i].positionComponent.position.y += ecs->entities[i].positionComponent.speed.dy;
        // update Animation
        if(ecs->ecs_delta%ecs->entities[i].sprite.frameDelay==0)
            ecs->entities[i].sprite.currentFrame++%ecs->entities[i].sprite.frameCount;   
    }
}

void ECS_DrawEntities(ECS *ecs)
{
    
    for (int i = 0; i < ecs->count; i++)
    {
        // Draw entity
        if (ecs->entities[i].visibilityComponent.visible)
        {   SpriteComponent sprite = ecs->entities[i].sprite;
            Transformation transform = ecs->entities[i].transform;
            //calculate Current Frame
            DrawTexturePro(sprite.texture,
                           (Rectangle){sprite.currentFrame * sprite.frameWidth,
                           sprite.currentAnim * sprite.frameHeight,
                           sprite.frameWidth,sprite.frameHeight},
                           (Rectangle){ecs->entities[i].positionComponent.position.x,
                            ecs->entities[i].positionComponent.position.y,sprite.frameWidth,sprite.frameHeight},(Vector2){0,0},transform.rotation, WHITE);
        }
    }
}