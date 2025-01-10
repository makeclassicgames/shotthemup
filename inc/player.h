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

#ifndef PLAYER_H
#define PLAYER_H
#include <raylib.h>
#include "physics.h"
#include "ecs.h"
#include "input.h"

 typedef struct Player Player;
    
 typedef void (*updatePlayer)(Player* player, InputState input);

 typedef struct Player{
        int entity_id;
        short lives;
        long score;
        updatePlayer update;
};
   

   

    void initPlayer(Player *player);
#endif