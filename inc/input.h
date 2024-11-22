#ifndef INPUT_H
#define INPUT_H

typedef enum input{
    UP,
    DOWN,
    LEFT,
    RIGHT,
    FIRE,
    START,
    NONE
}Input;

void initInput(void);
Input readInput(void);
#endif