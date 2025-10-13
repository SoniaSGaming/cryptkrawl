#include <ncurses/ncurses.h>
#include "surface.h"
#include <vector>
#include <string>
#include <fstream>

#ifndef _BLITTING_H_
#define _BLITTING_H_

void blit_surf(WINDOW * win, int x, int y, Surface surf) {
    int xMax, yMax;
    getmaxyx(win, yMax, xMax);

    init_pair(1, surf.fg, surf.bg);

    attron(COLOR_PAIR(1));
    for(int i=y, k=1;i<=yMax && i<surf.graphic.size();++i, ++k)
        mvwaddstr(win, i, x, surf.graphic[i]);
    attroff(COLOR_PAIR(1));

    refresh();
}