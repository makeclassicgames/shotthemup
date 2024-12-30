// Include Lib
#include <raylib.h>

#include "game.h"
#include "player.h"
#include "input.h"
#include "resources.h"


// prototype functions
void init(void);
void update(void);
void draw(void);


// Main Function
int main()
{

    Game* game = getCurrentGame();
    // Init()
    init();
    // While windows is open
    while (!WindowShouldClose())
    {
        readInput(&game->lastInput);
        // update()
        update();
        // Draw()
        draw();
    }
    deInitTextures();
    // Close Window
    CloseWindow();
    return 0;
}

// init()
void init(void)
{
    Game* game = getCurrentGame();
    // Init Window (width, Height, title)
    InitWindow(800, 450, "Shot Them Up");
    // Set target FPS
    SetTargetFPS(60);
    initTextures();
    initGame(game);
   
}

// update()
void update(void)
{

    Game* game = getCurrentGame();

     switch (game->status)
    {
    case INITIAL:
        if(game->lastInput.inputState[INPUT_START]){
            game->status=MENU;
        }
        break;
    case MENU:
        if(game->lastInput.inputState[INPUT_START]){
            game->status=GAME_LOOP;
        }
    case GAME_LOOP:
        game->player.update(&game->player,game->lastInput);
        updateSceneTimers(&game->gameScene);
        game->gameScene.update(&game->gameScene);
        break;
    
    default:
        break;
    }
}

// draw
void draw(void)
{
    Game* game = getCurrentGame();
    // init drawing mode
    BeginDrawing();
    // Clear Background
    ClearBackground(RAYWHITE);
    // Draw Text
    // Finish Drawing Mode
   
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
        
        game->gameScene.draw(&game->gameScene);
        break;
    
    default:
        break;
    }
    EndDrawing();
}