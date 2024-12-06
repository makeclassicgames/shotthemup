#include "ecs.h"

static int next_entity_id = 0;

void ECS_Init(ECS *ecs)
{
    ecs->count = 0;
}

Entity ECS_CreateEntity(ECS *ecs)
{
    Entity entity;
    entity.entity_id = next_entity_id;
    next_entity_id++;
    ecs->entities[ecs->count] = entity;
    ecs->count++;
    return entity;
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
    for (int i = 0; i < ecs->count; i++)
    {
        // update Position
        ecs->entities[i].component.pos.x += ecs->entities[i].component.speed.dx;
        ecs->entities[i].component.pos.y += ecs->entities[i].component.speed.dy;
    }
}

void ECS_DrawEntities(ECS *ecs)
{
    
    for (int i = 0; i < ecs->count; i++)
    {
        // Draw entity
        if (ecs->entities[i].component.visible)
        {   Sprite sprite = ecs->entities[i].component.sprite;
            //calculate Current Frame
            DrawTexturePro(sprite.texture,
                           (Rectangle){0,
                           0,sprite.frameWidth,sprite.frameHeight},
                           (Rectangle){ecs->entities[i].component.pos.x,
                            ecs->entities[i].component.pos.y,sprite.frameWidth,sprite.frameHeight},(Vector2){0,0},0.0f, WHITE);
        }
    }
}