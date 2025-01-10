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
#ifndef INPUT_H
#define INPUT_H

#include <raylib.h>

// Input Constants
/**
 * @brief Input UP
 */
#define INPUT_UP 0
/**
 * @brief Input DOWN
 */
#define INPUT_DOWN 1

/**
 * @brief Input LEFT
 */
#define INPUT_LEFT 2

/**
 * @brief Input RIGHT
 */
#define INPUT_RIGHT 3

/**
 * @brief Input FIRE
 */
#define INPUT_FIRE 4

/**
 * @brief Input START
 */
#define INPUT_START 5

/**
 * @brief Input State
 */
typedef struct
{
    bool inputState[6];
} InputState;


/**
 * @brief Initialize Input
 */
void initInput(void);

/**
 * @brief Read Input from Keyboard and gamepad
 * @param input Input State returned
 */
void readInput(InputState *);
#endif