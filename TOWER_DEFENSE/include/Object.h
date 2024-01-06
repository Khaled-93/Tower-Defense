
#ifndef __OBJECT
#define __OBJECT



#include "Config.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>




typedef struct {
    double x;
    double y;
} Object;

typedef struct Node {
    Object *elem;
    struct Node *next;
} NodeObject;

typedef struct List {
    NodeObject *head;
} ListObject;



Object *init_object(double x, double y);
void addToListObject(ListObject *list, Object *monster);
void freeMListObject(ListObject *list);

#endif
