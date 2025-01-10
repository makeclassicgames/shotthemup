/*
 * This file is part of Shot Them Up.
 *
 * Shot Them Up is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Shot Them Up is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Shot Them Up. If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef OBJECTS_H
#define OBJECTS_H

#include <raylib.h>

#include "ecs.h"


/**
 * @brief Initialize an enemy entity
 * @param entity Entity entity to be initialized
 * @param x X position
 * @param y Y position
 * @param texture Texture2D texture of the entity (sprite)
 * @param frameCount number of frames per animation
 * @param animCount number of animations
 * @param frameWidth width of a frame
 * @param frameHeight height of a frame
 * @param frameDelay delay between frames
 */
void initEnemyEntity(Entity *entity, float x,
                     float y, Texture2D texture,
                     int frameCount,
                     int animCount,
                     int frameWidth, int frameHeight, int frameDelay);


/**
 * @brief Initialize an Bullet entity
 * @param entity Entity entity to be initialized
 * @param x X position
 * @param y Y position
 * @param texture Texture2D texture of the entity (sprite)
 * @param frameCount number of frames per animation
 * @param animCount number of animations
 * @param frameWidth width of a frame
 * @param frameHeight height of a frame
 * @param frameDelay delay between frames
 */
void initBulletEntity(Entity *entity, float x,
                      float y, Texture2D texture,
                      int frameCount,
                      int animCount,
                      int frameWidth, int frameHeight, int frameDelay);


/**
 * @brief Initialize an Player entity
 * @param entity Entity entity to be initialized
 * @param x X position
 * @param y Y position
 * @param texture Texture2D texture of the entity (sprite)
 * @param frameCount number of frames per animation
 * @param animCount number of animations
 * @param frameWidth width of a frame
 * @param frameHeight height of a frame
 * @param frameDelay delay between frames
 */
void initPlayerEntity(Entity *entity, float x,
                      float y, Texture2D texture,
                      int frameCount,
                      int animCount,
                      int frameWidth, int frameHeight, int frameDelay);
#endif // OBJECTS_H