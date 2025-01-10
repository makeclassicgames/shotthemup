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

#ifndef PROPERTIES_H
#define PROPERTIES_H

#include <raylib.h>

typedef void* PropertyValue;

/**
 * @brief Key Value Type
 */
typedef struct{
char key[50];
PropertyValue value;
}KeyValue;

/**
 * @brief Create a key value pair
 * @param key Key
 * @param value Value
 * @return KeyValue created
 */
KeyValue createKeyValue(const char* key, PropertyValue value);

/**
 * @brief Add a property to an entity
 * @param keyValue KeyValue to get
 * @param value Value getted
 */
void getValue(KeyValue* keyValue, void * value);
#endif