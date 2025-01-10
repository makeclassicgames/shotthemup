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

#include "resources.h"
#include <raylib.h>
#include <stdio.h>

#define GFX_TEXTURES_PATH "../resources/gfx/%s"
#define SPRITES_TEXTURES_PATH "../resources/sprites/%s"
#define MAX_RES 100

Texture2D gfxTextures[MAX_RES];

Texture2D spriteTextures[MAX_RES];

void initTextures(void)
{
    char buffer[60];
    sprintf(buffer, GFX_TEXTURES_PATH, "title.png");

    gfxTextures[TITLE_SCREEN] = LoadTexture(buffer);

    sprintf(buffer, GFX_TEXTURES_PATH, "map.png");
    gfxTextures[SKY_BG] = LoadTexture(buffer);
    // Sprites
    sprintf(buffer, SPRITES_TEXTURES_PATH, "navesprt.png");
    spriteTextures[SPRITE_PLAYER_1] = LoadTexture(buffer);
    // Enemy Sprite
    sprintf(buffer, SPRITES_TEXTURES_PATH, "enemy.png");
    spriteTextures[SPRITE_ENEMY_1] = LoadTexture(buffer);
    // Bullet Sprite
    sprintf(buffer, SPRITES_TEXTURES_PATH, "bullet.png");
    spriteTextures[SPRITE_BULLET] = LoadTexture(buffer);
}

Texture2D getSpriteTexture(int id)
{
    return spriteTextures[id];
}

Texture2D getGfxTexture(int id)
{
    return gfxTextures[id];
}

void deInitTextures(void)
{
    UnloadTexture(getGfxTexture(TITLE_SCREEN));
    UnloadTexture(getGfxTexture(SKY_BG));
    UnloadTexture(getSpriteTexture(SPRITE_PLAYER_1));
    UnloadTexture(getSpriteTexture(SPRITE_ENEMY_1));
    UnloadTexture(getSpriteTexture(SPRITE_BULLET));
}