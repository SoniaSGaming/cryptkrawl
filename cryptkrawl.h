#include <ncurses.h>
#include <vector>
#include <string>
#include <fstream>

#ifndef _CRYPTKRAWL_H_
#define _CRYPTKRAWL_H_

void matrix_to_screen(WINDOW * win, std::vector<std::string> t, int yp, int xp)
{
    int xMax, yMax;
    getmaxyx(win,yMax,xMax);
    xMax-=2;
    yMax-=2;
    int xStart = xp-xMax/2, yStart = yp-yMax/2;

    for(int i=yStart, y=1;i<yStart+yMax;++i,++y)
    {
        for(int j=xStart, x=1;j<xStart+xMax;++j,++x)
            if(j<0 || i<0 || i>=t.size() || j>=t[i].size())
                mvwaddch(win, y, x, '@');
            else
                mvwaddch(win, y, x, t[i][j]);
    }

    wrefresh(win);
}

void init_matrix(std::vector<std::string> & s, int y, int x, char ch)
{
    for(int i=0;i<y;++i)
    {
        std::string f;
        for(int j=0;j<x;++j)
            f.push_back(ch);
        
        s.push_back(f);
    }
}

#endif
