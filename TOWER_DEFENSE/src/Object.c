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

void addToListObject(ListObject *list, Object *monster) {
    NodeObject *newNode = (NodeObject*)malloc(sizeof(NodeObject));
    if (newNode == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire pour le nouvel élément de la liste\n");
        exit(EXIT_FAILURE);
    }

    newNode->elem = monster;
    newNode->next = list->head;
    list->head = newNode;
}

void freeMListObject(ListObject *list) {
    NodeObject *current = list->head;
    while (current != NULL) {
        NodeObject *next = current->next;
        free(current->elem); 
        free(current); 
        current = next;
    }
    free(list);
}
