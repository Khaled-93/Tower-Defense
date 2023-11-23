#ifndef __MONSTER
#define __MONSTER

#include "all.h"




typedef enum{
    LEFT,
    RIGHT,
    UP,
    DOWN
} Monster_Direction;


typedef struct{
    Object obj;
    int pv;
    double speed;
    Monster_Direction direction;
}Monster;









#endif