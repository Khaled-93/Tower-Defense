#include "../include/Tower.h"


Tower *init_tower(double x, double y) {
    Tower *new;
    Object *obj;

    new = (Tower *)malloc(sizeof(Tower));
    obj = init_object(x, y);

    if (NULL == new) {
        fprintf(stderr, "Failed to init Player...\n");
        exit(EXIT_FAILURE);
    }

    new->obj = *obj;
    new->mana = MAX_MANA;
    new->score = 0;

    free(obj);
    return new;
}