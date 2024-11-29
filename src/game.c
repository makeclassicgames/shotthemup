#include <raylib.h>
#include "player.h"
#include "game.h"
#include "resources.h"

void initGame(Game * game){
    initPlayer(&game->player);
    game->status=INITIAL;
}

void updateGame(Game * game){

    switch (game->status)
    {
    case INITIAL:
        if(game->lastInput==START){
            game->status=MENU;
        }
        break;
    case MENU:
        if(game->lastInput==START){
            game->status=GAME_LOOP;
        }
    case GAME_LOOP:
        updatePlayer(&game->player,game->lastInput);
        break;
    
    default:
        break;
    }
}

void drawGame(Game* game){
    switch (game->status)
    {
    case INITIAL:
        DrawText("Initial State", 290, 200, 20, BLACK);
        break;
    case MENU:
        Texture2D texture= getGfxTexture(TITLE_SCREEN);
        DrawTexture(texture,0,0,WHITE);
        break;
    case GAME_LOOP:
        DrawText("Game Loop", 290, 200, 20, BLACK);
        DrawTextureEx(getGfxTexture(SKY_BG),
                    (Vector2){0,0},
                    0.0f,4.0f,WHITE);
        //DrawTexture(,0,0,WHITE);
        drawPlayer(&game->player);
        break;
    
    default:
        break;
    }
}