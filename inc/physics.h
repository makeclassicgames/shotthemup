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
#endif