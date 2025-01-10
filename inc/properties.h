#ifndef PROPERTIES_H
#define PROPERTIES_H

#include <raylib.h>

typedef void* PropertyValue;

typedef struct{
char key[50];
PropertyValue value;
}KeyValue;

KeyValue createKeyValue(const char* key, PropertyValue value);
void getValue(KeyValue* keyValue, void * value);
#endif