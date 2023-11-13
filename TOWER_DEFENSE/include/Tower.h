#ifndef __TOWER
#define __TOWER 


#include "Object.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




typedef struct {
    Object obj;
    int score;
    int mana;
    /*ajouter les autres fonctionalités*/
} Tower;



Tower *init_tower(double x, double y);


#endif