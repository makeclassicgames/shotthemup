// Include Lib
#include <raylib.h>

#include "player.h"
#include "input.h"

// prototype functions
void init(void);
void update(void);
void draw(void);

Player * player;
Input input;

// Main Function
int main()
{

    // Init()
    init();
    // While windows is open
    while (!WindowShouldClose())
    {
        input = readInput();
        // update()
        update();
        // Draw()
        draw();
    }
    // Close Window
    CloseWindow();
    return 0;
}

// init()
void init(void)
{
    // Init Window (width, Height, title)
    InitWindow(800, 450, "Hello Raylib");
    // Set target FPS
    SetTargetFPS(60);

    initPlayer(&player);
}

// update()
void update(void)
{

    updatePlayer(&player, input);
}

// draw
void draw(void)
{
    // init drawing mode
    BeginDrawing();
    // Clear Background
    ClearBackground(RAYWHITE);
    // Draw Text
    DrawText("Hello Raylib", 290, 200, 20, BLACK);
    // Finish Drawing Mode
   
    drawPlayer(&player);
    EndDrawing();
}