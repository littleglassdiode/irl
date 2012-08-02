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

#include <stdbool.h>
#include <string.h>

#include <curses.h>

#include "input.h"
#include "entity.h"

#define WIDTH 80
#define HEIGHT 24

char *map[] = {
    "########################",
    "#.......#..............#",
    "#.......#...........##.#",
    "#...................#..#",
    "#########...........#.##",
    "#...................#..#",
    "#.......#...........##.#",
    "#.......#..............#",
    "########################"
};


int main(int argc, char **argv)
{
    Entity rae = {{1, 1}, true, true, 12, 12, '@'};
    bool gameover = false;
    char c = '\0';

    /* Initialize curses */
    initscr();
    curs_set(0);
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, FALSE);
#ifdef DEBUG /* Let ^C cause an interrupt if it's a debug build */
    cbreak();
#else /* Otherwise, send it to the program for it to be ignored */
    raw();
#endif

    do {
        mvprintw(0, 0, "There are cockroaches in your mouth.");
        mvprintw(HEIGHT-1, 0, "%s:  HP %i/%i  Arm: %i  PE: %i/%i  ME: %i/%i",
                 "Rae", rae.hp, rae.max_hp,  5,  18, 20,  28, 34);
        for (int i = 0; i < 9; i++) {
            mvprintw(i+1, 0, map[i]);
        }
        mvaddch(rae.v.y+1, rae.v.x, rae.c);
        refresh();
        c = input();
        if (c == 'Q') {
            gameover = true;
        }
        ent_move(&rae, c);
    } while (!gameover);

    /* Clean up this mess we've gotten ourselves into */
    erase();
    refresh();
    endwin();

    return 0;
}
