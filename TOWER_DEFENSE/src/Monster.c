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
    tmp->speed = SPEED_MONSTER;


    return tmp;
}

void addToListMonster(ListMonster *list, Monster *monster) {
    NodeMonster *newNode = (NodeMonster *)malloc(sizeof(NodeMonster));
    if (newNode == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire pour le nouvel élément de la liste\n");
        exit(EXIT_FAILURE);
    }

    newNode->elem = monster;
    newNode->next = list->head;
    list->head = newNode;
}

void freeMListMonster(ListMonster *list) {
    NodeMonster *current = list->head;
    while (current != NULL) {
        NodeMonster *next = current->next;
        free(current->elem);
        free(current);
        current = next;
    }
    free(list);
}