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

#ifndef PHYSICS_H
#define PHYSICS_H
    typedef struct{
        float x;
        float y;
    }Point;

    typedef struct{
        float dx;
        float dy;
    }Speed;

    typedef struct{
        float rotation;
        float scale;
    }Transformation;

    typedef struct{
        float xoffset;
        float yoffset;
        float width;
        float height;
    }Collider;
#endif