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

typedef struct NodeMonster {
    Monster *elem;
    struct NodeMonster *next;
} NodeMonster;

typedef struct {
    NodeMonster *head;
} ListMonster;



Monster *init_monster(double x , double y);
void addToListMonster(ListMonster *list, Monster *monster);
void freeMListMonster(ListMonster *list);

#endif