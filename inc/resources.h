#ifndef RESOURCES_H
#define RESOURCES_H

#include <raylib.h>

#define TITLE_SCREEN 0
#define SKY_BG 1

#define SPRITE_PLAYER_1 0
#define SPRITE_ENEMY_1 1


void initTextures(void);
void deInitTextures(void);

Texture2D getSpriteTexture(int);

Texture2D getGfxTexture(int);
#endif