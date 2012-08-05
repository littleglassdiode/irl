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

#include <string.h>

#include <curses.h>

#include "input.h"
#include "entity.h"

#define STATSWIDTH 10
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
    WINDOW *stats = NULL;
    WINDOW *field = NULL;

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

    stats = newwin(HEIGHT, STATSWIDTH, 0, 0);
    field = newwin(HEIGHT, WIDTH-STATSWIDTH, 0, 10);

    do {
        wattron(stats, A_BOLD);
        mvwprintw(stats, 0, 0, "Rae");
        wattroff(stats, A_BOLD);
        mvwprintw(stats, 1, 0, "Level %-3i", 3);
        mvwprintw(stats, 3, 0, "Health");
        mvwprintw(stats, 4, 0, "%i/%i", rae.hp, rae.max_hp);
        mvwprintw(stats, 6, 0, "Armor");
        mvwprintw(stats, 7, 0, "%i", 5);
        mvwprintw(stats, 9, 0, "Physic.En");
        mvwprintw(stats, 10, 0, "%i/%i", 18, 20);
        mvwprintw(stats, 12, 0, "Mental.En");
        mvwprintw(stats, 13, 0, "%i/%i", 34, 34);
        for (int i = 0; i < HEIGHT-1; i++)
            mvwaddch(stats, i, STATSWIDTH-1, ACS_VLINE);
        mvwaddch(stats, 2, 9, ACS_RTEE);
        for (int i = 0; i < STATSWIDTH-1; i++)
            mvwaddch(stats, 2, i, ACS_HLINE);

        for (int i = 0; i < 9; i++) {
            mvwprintw(field, i, 0, map[i]);
        }
        wattron(field, A_BOLD);
        mvwaddch(field, rae.v.y, rae.v.x, rae.c);
        wattroff(field, A_BOLD);
        refresh();
        wrefresh(stats);
        wrefresh(field);
        c = input();
        if (c == 'Q')
            gameover = true;
        ent_move(&rae, c);
    } while (!gameover);

    /* Clean up this mess we've gotten ourselves into */
    delwin(stats);
    stats = NULL;
    delwin(field);
    field = NULL;
    erase();
    refresh();
    endwin();

    return 0;
}
