#include "input.h"
#include <raylib.h>

void initInput(void)
{
}

Input readInput(void)
{
    Input result = NONE;
    if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S))
    {
        result = DOWN;
    }
    else
    {
        if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W))
        {
            result = UP;
        }
        else
        {
            if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A))
            {
                result = LEFT;
            }
            else
            {
                if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D))
                {
                    result = RIGHT;
                }
                else
                {
                    if (IsKeyPressed(KEY_SPACE))
                    {
                        result = FIRE;
                    }
                    else
                    {
                        if (IsKeyPressed(KEY_ENTER))
                        {
                            result = START;
                        }
                    }
                }
            }
        }
        
    }
    return result;
}