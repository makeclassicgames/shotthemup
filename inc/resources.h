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

#ifndef RESOURCES_H
#define RESOURCES_H

#include <raylib.h>

#define TITLE_SCREEN 0
#define SKY_BG 1

#define SPRITE_PLAYER_1 0
#define SPRITE_ENEMY_1 1
#define SPRITE_BULLET 2


void initTextures(void);
void deInitTextures(void);

Texture2D getSpriteTexture(int);

Texture2D getGfxTexture(int);
#endif