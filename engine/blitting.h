#include <ncurses.h>
#include "surface.h"
#include <vector>
#include <string>
#include <fstream>

#ifndef _BLITTING_H_
#define _BLITTING_H_

void init_color_pairs() {
    init_pair(7,7,0);
    init_pair(2,2,0);
    init_pair(3,3,0);
    init_pair(4,4,0);
    init_pair(5,5,0);
    init_pair(6,6,0);
    init_pair(1,1,0);
}

void blit_surf(WINDOW * win, int x, int y, Surface surf) {
    int xMax, yMax;
    getmaxyx(win, yMax, xMax);

    attron(COLOR_PAIR(surf.color));
    
    for(int k=0;k+y<=yMax && k<surf.graphic.size();++k)
        for(int j=0;j<surf.graphic[k].size() && x+j<=xMax;++j){
            mvwaddch(win, y+k, x+j, surf.graphic[k][j]);
        }
    attroff(COLOR_PAIR(surf.color));

    refresh();
}

#endif