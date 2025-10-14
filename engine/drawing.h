#include <ncurses.h>
#include "surface.h"
#include <vector>
#include <string>
#include <fstream>
#include <utility>
#include <cmath>

#ifndef _DRAWING_H_
#define _DRAWING_H_

void init_color_pairs() {
    init_pair(7,7,0);
    init_pair(2,2,0);
    init_pair(3,3,0);
    init_pair(4,4,0);
    init_pair(5,5,0);
    init_pair(6,6,0);
    init_pair(1,1,0);
}


//BRESENHAM'S ALGORITHM
void draw_line(WINDOW * win, std::pair<int, int> point1, std::pair<int, int> point2, char ch, int color=7)
{
    attron(COLOR_PAIR(color));

    int dx=std::abs(point2.first - point1.first);
    int sx = point1.first < point2.first ? 1 : -1;
    int dy=-std::abs(point2.second - point1.second);
    int sy = point1.second < point2.second ? 1 : -1;
    int error = dx+dy;

    while(true)
    {
        mvwaddch(win, point1.second, point1.first, ch);
        int e2 = 2*error;
        if(e2>=dy)
        {
            if(point1.first == point2.first) break;
            error += dy;
            point1.first += sx;
        }
        if(e2<=dx)
        {
            if(point1.second == point2.second) break;
            error += dx;
            point1.second += sy;
        }
    }

    attroff(COLOR_PAIR(color));
}

void draw_surf(WINDOW * win, std::pair<int, int> pos, Surface surf) {
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
