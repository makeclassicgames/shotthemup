#include "input.h"
#include <raylib.h>

void readGamepadInput(InputState *);

void initInput(void)
{
}

void readInput(InputState * state)
{


    for(int i=0;i<6;i++)
    {
        state->inputState[i]=false;
    }

    if(IsGamepadAvailable(0))
    {
        readGamepadInput(state);
    }
    else
    {
        state->inputState[INPUT_DOWN]=IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S);
        state->inputState[INPUT_UP]=IsKeyDown(KEY_UP) || IsKeyDown(KEY_W);
        state->inputState[INPUT_LEFT]=IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A);
        state->inputState[INPUT_RIGHT]=IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D);
        state->inputState[INPUT_FIRE]=IsKeyPressed(KEY_SPACE);
        state->inputState[INPUT_START]=IsKeyPressed(KEY_ENTER);
        state->inputState[INPUT_FIRE]=IsKeyPressed(KEY_SPACE);
        state->inputState[INPUT_START]=IsKeyPressed(KEY_ENTER);
    }
  
}

void readGamepadInput(InputState *state){
 
    if(GetGamepadAxisMovement(0,GAMEPAD_AXIS_LEFT_Y)>0)
    {
        state->inputState[INPUT_DOWN]=true;
    }
    else if(GetGamepadAxisMovement(0,GAMEPAD_AXIS_LEFT_Y)<0)
    {
        state->inputState[INPUT_UP]=true;
    }

    if(GetGamepadAxisMovement(0,GAMEPAD_AXIS_LEFT_X)>0)
    {
        state->inputState[INPUT_RIGHT]=true;
    }else if(GetGamepadAxisMovement(0,GAMEPAD_AXIS_LEFT_X)<0)
    {
        state->inputState[INPUT_LEFT]=true;
    }
  
    if(IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){
        state->inputState[INPUT_FIRE]=true;
    }

    if(IsGamepadButtonDown(0, GAMEPAD_BUTTON_MIDDLE_RIGHT)){
        state->inputState[INPUT_START]=true;
    }
}
