#ifndef VECTOR_H
#define VECTOR_H


typedef struct {
    unsigned int y;
    unsigned int x;
} Vector;

Vector vec_add(const Vector, const Vector);
Vector dir_to_vec(int dir);


#endif /* VECTOR_H */

/* ex: syntax=c shiftwidth=4 expandtab
 */
