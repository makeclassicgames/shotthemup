#ifndef INPUT_H
#define INPUT_H

#include <raylib.h>

#define INPUT_UP 0
#define INPUT_DOWN 1
#define INPUT_LEFT 2
#define INPUT_RIGHT 3
#define INPUT_FIRE 4
#define INPUT_START 5
#define INPUT_NONE 6

typedef struct
{
    bool inputState[6];
} InputState;

void initInput(void);
void readInput(InputState *);
#endif