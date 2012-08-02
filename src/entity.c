#include "entity.h"

extern char *map[];


void ent_move(Entity *ent, const int dir)
{
    Vector v = vec_add(dir_to_vec(dir), ent->v);
    if (map[v.y][v.x] == '.') {
        ent->v = v;
    }
}


/* ex: syntax=c shiftwidth=4 expandtab
 */
