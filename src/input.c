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

#include "input.h"


int input(void)
{
    int c = getch();

    switch (c) {
        case '4':
        case KEY_LEFT:
        case 'h':
            return 'h';
        case '2':
        case KEY_DOWN:
        case 'j':
            return 'j';
        case '8':
        case KEY_UP:
        case 'k':
            return 'k';
        case '6':
        case KEY_RIGHT:
        case 'l':
            return 'l';
        case '7':
        case KEY_HOME:
        case 'y':
            return 'y';
        case '9':
        case KEY_PPAGE:
        case 'u':
            return 'u';
        case '1':
        case KEY_END:
        case 'b':
            return 'b';
        case '3':
        case KEY_NPAGE:
        case 'n':
            return 'n';
        case 'Q':
            return 'Q';
        default:
            return c;
    }
}

