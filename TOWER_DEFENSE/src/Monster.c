#include "../include/Monster.h"






Monster *init_monster(double x , double y){
    Monster *tmp;
    Object *obj;
    
    tmp = (Monster *)malloc(sizeof(Monster));
    if(NULL == tmp)
        return NULL;

    obj = init_object(x, y);

    tmp->obj = *obj;
    tmp->pv = PV_MONSTER;
    tmp->speed = SPEED_MONSTER; /*a voir*/


    return tmp;
}