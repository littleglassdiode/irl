#ifndef ENTITY_H
#define ENTITY_H

#include <stdbool.h>
#include "vector.h"


typedef struct {
    Vector v;
    bool is_animal;
    bool is_alive;
    short max_hp;
    short hp;
    const char c;
} Entity;

void ent_move(Entity *, const int);


#endif /* ENTITY_H */

/* ex: syntax=c shiftwidth=4 expandtab
 */
