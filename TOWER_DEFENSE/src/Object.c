#include "../include/Object.h"





Object *init_object(double x, double y){
    Object *new;

    new = (Object*) malloc(sizeof(Object));
    if(NULL == new)
        return NULL;
    
    new->x = x;
    new->y = y;

    return new;
}


