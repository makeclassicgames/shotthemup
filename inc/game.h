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
#ifndef GAME_H
#define GAME_H

#include "ecs.h"
#include "player.h"
#include "timer.h"

typedef enum state{
    INITIAL,
    MENU,
    GAME_LOOP,
    GAME_OVER,
    WIN
}Status;

typedef struct{
    Scene gameScene;
    Player player;
    Status status;
    InputState lastInput;
}Game;

Game * getCurrentGame(void);
void initGame(Game * );

#endif