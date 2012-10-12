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

#include "main.h"


int mapheight = 29, mapwidth = 79;
char *map[] = {
    "                         ###                                                   ",
    "                         #.##                                                  ",
    "                         ##.##                                                 ",
    "                          ##.##                                                ",
    "                           ##.##                         ######################",
    "                            ##.##                       ##....................#",
    "                             ##.###################    ##.....................#",
    "                       #########..................##   #......................#",
    "                       #.......#...................#   #......#################",
    "                       #.......#...................#   #......................#",
    "########################.......#...................#   #......................#",
    "#.......#..........====#.......#...................#####......................#",
    "#.......#..............####.####..............................................#",
    "#........................................##...................................#",
    "#########................................##...................................#",
    "#........................................##...................................#",
    "#.......#..............####.####..............................................#",
    "#.......#..........====#.......#...................#####......................#",
    "########################.......#...................#   #......................#",
    "                       #.......#...................#   #......................#",
    "                       #.......#...................#   #......#################",
    "                       #########..................##   #......................#",
    "                             ##.###################    ##.....................#",
    "                            ##.##                       ##....................#",
    "                           ##.##                         ######################",
    "                          ##.##                                                ",
    "                         ##.##                                                 ",
    "                         #.##                                                  ",
    "                         ###                                                   "
};

bool gameover = false;

int main(int argc, char **argv)
{
    struct actor rae = {1, {11, 1}, 12, 12, '@'};
    WINDOW *stats = NULL;
    WINDOW *field = NULL;
    int starty = 0;
    int startx = 0;

    /* Initialize curses */
    initscr();
    curs_set(0);
    noecho();
    nonl();
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
        mvwprintw(stats, 3, 0, "Health\n%i/%i", rae.hp, rae.max_hp);
        mvwprintw(stats, 6, 0, "Armor %i", 5);
        mvwprintw(stats, 8, 0, "Physic.En\n%i/%i", 18, 20);
        mvwprintw(stats, 11, 0, "Mental.En\n%i/%i", 34, 34);
        for (int i = 0; i < HEIGHT; i++)
            mvwaddch(stats, i, STATSWIDTH-1, ACS_VLINE);
        mvwaddch(stats, 2, 9, ACS_RTEE);
        for (int i = 0; i < STATSWIDTH-1; i++)
            mvwaddch(stats, 2, i, ACS_HLINE);

        if (rae.pos.x < (startx + 15) && startx > 0) {
            startx--;
        }
        if (rae.pos.x > (startx + FIELDWIDTH - 16) && startx + FIELDWIDTH <
                mapwidth) {
            startx++;
        }
        if (rae.pos.y < (starty + 7) && starty > 0) {
            starty--;
        }
        if (rae.pos.y > (starty + HEIGHT - 8) && starty + HEIGHT < mapheight) {
            starty++;
        }
        for (int i = starty; i < starty + HEIGHT; i++) {
            mvwprintw(field, i-starty, 0, map[i]+startx);
        }
        wattron(field, A_BOLD);
        mvwaddch(field, rae.pos.y-starty, rae.pos.x-startx, rae.c);
        wattroff(field, A_BOLD);
        refresh();
        wrefresh(stats);
        wrefresh(field);
        ai_list[rae.ai](&rae);
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
