#include "../include/all.h"






Tower *init_Tower(double x, double y){
    Tower *new;

    new = (Tower*) malloc(sizeof(Tower));
    if(NULL == new)
        return NULL;
    
    new->x = x;
    new->y = y;

    return new;
}


