/* Copyright (c) 2012 Clayton G. Hobbs
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

#include "level.h"


struct level *alloc_level(int y, int x)
{
    struct level *level = calloc(1, sizeof (level));

    if (level == NULL) {
        free_level(level);
        return NULL;
    }

    level->size.y = y;
    level->size.x = x;
    level->map = calloc(y, sizeof (char *));
    if (level->map == NULL) {
        free_level(level);
        return NULL;
    }
    for (y--; y >= 0; y--) {
        level->map[y] = calloc(x + 1, sizeof (char));
        if (level->map[y] == NULL) {
            free_level(level);
            return NULL;
        }
    }
    level->actors = calloc(ACTOR_MAX, sizeof (struct actor));
    if (level->actors == NULL) {
        free_level(level);
        return NULL;
    }

    return level;
}

void free_level(struct level *level)
{
    free(level->actors);
    level->actors = NULL;

    for (int y = 0; y < level->size.y; y++) {
        free(level->map[y]);
        level->map[y] = NULL;
    }

    free(level->map);
    level->map = NULL;

    free(level);
}
