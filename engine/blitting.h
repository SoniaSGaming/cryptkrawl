#include <ncurses.h>
#include "surface.h"
#include <vector>
#include <string>
#include <fstream>
#include <utility>

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

void blit_surf(WINDOW * win, std::pair<int, int> pos, Surface surf) {
    int xMax, yMax;
    getmaxyx(win, yMax, xMax);

    attron(COLOR_PAIR(surf.color));
    
    for(int i=0;i+pos.second<=yMax && i<surf.size.second;++i)
        for(int j=0;j<surf.size.first && pos.first+j<=xMax;++j){
            mvwaddch(win, pos.second+i, pos.first+j, surf.graphic[i][j]);
        }
    attroff(COLOR_PAIR(surf.color));

    refresh();
}

#endif
