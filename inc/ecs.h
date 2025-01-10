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


//Background
typedef struct{
    Texture2D texture;
    int xoffSet;
    int yoffSet;
    Rectangle rect;
}Background;




typedef Transformation TransformComponent;
//Sprite Component
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

//Position Component
typedef struct{
    Point position;
    Speed speed;
}PositionComponent;

//Visibility Component
typedef struct{
    bool visible;
}VisibilityComponent;

//Tags Component
typedef struct{
    char tag[MAX_TAGS][30];
    int tagCount;
}TagComponent;

//Property Component
typedef struct{
    KeyValue properties[MAX_PROPERTIES];
    int propertyCount;
}PropertyComponent;

//Entity
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

//ECSSystem
typedef struct{
    Entity entities[MAX_ENTITIES];
    int count;
    int ecs_delta;
}ECS;

typedef struct Scene Scene;

typedef void (*updateScene)(Scene *self);
typedef void (*drawScene)(Scene *self);
typedef void (*initScene)(Scene *self, Background Background);

//Scene
/**
 * @brief Scene Definition
 */
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



//ECS Functions

/**
 * @brief Initialize the ECS System
 * @param ecs ECS System
 */
void ECS_Init(ECS *ecs);

/**
 * @brief Create an Entity
 * @param ecs ECS System
 * @return Entity ID created
 */
int ECS_CreateEntity(ECS *ecs);

/**
 * @brief Destroy an Entity
 * @param ecs ECS System
 * @param entity_id Entity ID to destroy
 */
void ECS_DestroyEntity(ECS *ecs, int entity_id);

/**
 * @brief Update all entities in the ECS System
 * @param ecs ECS System
 */
void ECS_UpdateEntities(ECS *ecs);

/**
 * @brief Draw all entities in the ECS System
 * @param ecs ECS System
 */
void ECS_DrawEntities(ECS *ecs);

/**
 * @brief Get an Entity by ID
 * @param ecs ECS System
 * @param entity_id Entity ID
 * @return Entity or entity with entity_id = -1 if not found
 */
Entity ECS_GetEntity(ECS *ecs, int entity_id);

/**
 * @brief Set an Entity by ID
 * @param ecs ECS System
 * @param entity_id Entity ID
 * @param entity Entity to set
 */
void ECS_SetEntity(ECS *ecs, int entity_id, Entity entity);

/**
 * @brief Check if two entities are colliding
 * @param entity1 Entity 1
 * @param entity2 Entity 2
 * @return true if colliding, false otherwise
 */
bool ECS_EntityIsColliding(Entity *entity1, Entity *entity2);

//Tag System
/**
 * @brief Add a tag to an entity
 * @param entity Entity
 * @param tag Tag to add
 */
void addTag(Entity *entity, const char *tag);

/**
 * @brief Remove a tag from an entity
 * @param entity Entity
 * @param tag Tag to remove
 */
void removeTag(Entity *entity, const char *tag);

/**
 * @brief Check if an entity has a tag
 * @param entity Entity
 * @param tag Tag to check
 * @return true if entity has tag, false otherwise
 */
bool hasTag(Entity *entity, const char *tag);

/**
 * @brief Search entities by tag
 * @param ecs ECS System
 * @param tag Tag to search
 * @param entities Array of entities found
 * @param count Number of entities found
 */
void searchByTag(ECS *ecs, const char *tag, Entity *entities, int *count);

//Timer Scene

/**
 * @brief Add a timer to a scene
 * @param scene Scene
 * @param maxTime Maximum time for the timer
 * @param callback Callback function to call when timer ends
 * @param repeat Repeat the timer
 */
void addTimerToScene(Scene *scene, long maxTime, TimerCallback callback, bool repeat);
/**
 * @brief Update all timers in a scene
 * @param scene Scene
 */
void updateTimers(Scene *scene);

//Properties System

/**
 * @brief Add a property to an entity
 * @param entity Entity
 * @param key Key of the property
 * @param value Value of the property
 */
void addProperty(Entity *entity, const char *key, PropertyValue value);

/**
 * @brief Remove a property from an entity
 * @param entity Entity
 * @param key Key of the property
 */
void removeProperty(Entity *entity, const char *key);

/**
 * @brief Get a property from an entity
 * @param entity Entity
 * @param key Key of the property
 * @param value Value of the property returned
 */
void getProperty(Entity *entity, const char *key, PropertyValue *value);
#endif