#include "vector.h"


Vector vec_add(const Vector v1, const Vector v2)
{
    Vector result;
    result.x = v1.x + v2.x;
    result.y = v1.y + v2.y;
    return result;
}

Vector dir_to_vec(int dir)
{
    Vector v = {0, 0};

    switch (dir) {
        case 'h':
            v.x = -1;
            break;
        case 'j':
            v.y = 1;
            break;
        case 'k':
            v.y = -1;
            break;
        case 'l':
            v.x = 1;
            break;
        case 'y':
            v.y = -1;
            v.x = -1;
            break;
        case 'u':
            v.y = -1;
            v.x = 1;
            break;
        case 'b':
            v.y = 1;
            v.x = -1;
            break;
        case 'n':
            v.y = 1;
            v.x = 1;
            break;
        default:
            v.y = 0; /* I know these are redundant, but the compiler should */
            v.x = 0; /* optimize them out if they're that bad. */
            break;
    }

    return v;
}


/* ex: syntax=c shiftwidth=4 expandtab
 */
