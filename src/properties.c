#include <string.h>
#include "properties.h"

KeyValue createKeyValue(const char *key, PropertyValue value)
{
    KeyValue keyValue;
    strcpy(keyValue.key, key);
    keyValue.value = value;
    return keyValue;
}

void getValue(KeyValue *keyValue, void *value)
{
    value = keyValue->value;
}