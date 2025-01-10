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

#include "input.h"
#include <raylib.h>

void readGamepadInput(InputState *);

void initInput(void)
{
}

void readInput(InputState *state)
{

    InputState gamepadState;
    for (int i = 0; i < 6; i++)
    {
        state->inputState[i] = false;
        gamepadState.inputState[i] = false;
    }

    if (IsGamepadAvailable(0))
    {
        readGamepadInput(&gamepadState);
    }
    state->inputState[INPUT_DOWN] = gamepadState.inputState[INPUT_DOWN] || (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S));
    state->inputState[INPUT_UP] = gamepadState.inputState[INPUT_UP] || (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W));
    state->inputState[INPUT_LEFT] = gamepadState.inputState[INPUT_LEFT] || (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A));
    state->inputState[INPUT_RIGHT] = gamepadState.inputState[INPUT_RIGHT] || (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D));
    state->inputState[INPUT_FIRE] = gamepadState.inputState[INPUT_FIRE] || IsKeyPressed(KEY_SPACE);
    state->inputState[INPUT_START] = gamepadState.inputState[INPUT_START] || IsKeyPressed(KEY_ENTER);
}

void readGamepadInput(InputState *state)
{

    if (GetGamepadAxisMovement(0, GAMEPAD_AXIS_LEFT_Y) > 0)
    {
        state->inputState[INPUT_DOWN] = true;
    }
    else if (GetGamepadAxisMovement(0, GAMEPAD_AXIS_LEFT_Y) < 0)
    {
        state->inputState[INPUT_UP] = true;
    }

    if (GetGamepadAxisMovement(0, GAMEPAD_AXIS_LEFT_X) > 0)
    {
        state->inputState[INPUT_RIGHT] = true;
    }
    else if (GetGamepadAxisMovement(0, GAMEPAD_AXIS_LEFT_X) < 0)
    {
        state->inputState[INPUT_LEFT] = true;
    }

    if (IsGamepadButtonPressed(0, GAMEPAD_BUTTON_RIGHT_FACE_DOWN))
    {
        state->inputState[INPUT_FIRE] = true;
    }

    if (IsGamepadButtonPressed(0, GAMEPAD_BUTTON_MIDDLE_RIGHT))
    {
        state->inputState[INPUT_START] = true;
    }

    // D-pad
    if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_DOWN))
    {
        state->inputState[INPUT_DOWN] = true;
    }
    if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_UP))
    {
        state->inputState[INPUT_UP] = true;
    }
    if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_LEFT))
    {
        state->inputState[INPUT_LEFT] = true;
    }
    if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_RIGHT))
    {
        state->inputState[INPUT_RIGHT] = true;
    }
}
