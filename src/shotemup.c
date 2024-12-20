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
    InitWindow(800, 450, "Hello Raylib");
    // Set target FPS
    SetTargetFPS(60);
    initTextures();
    initGame(game);
   
}

// update()
void update(void)
{

    Game* game = getCurrentGame();
    updateGame(game);
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
   
    drawGame(game);
    EndDrawing();
}