/* Copyright (c) 2012-2014 Clayton G. Hobbs
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include "vector.h"


struct vector vec_add(const struct vector *v1, const struct vector *v2)
{
    struct vector result;
    result.x = v1->x + v2->x;
    result.y = v1->y + v2->y;
    return result;
}

struct vector dir_to_vec(int dir)
{
    struct vector v = {0, 0};

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
