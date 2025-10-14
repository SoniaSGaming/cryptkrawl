#include <ncurses.h>
#include <vector>
#include <string>
#include <fstream>
#include <utility>
#include <cmath>
#include "gamengine.h"

Screen::Screen(std::pair<int, int> pos, std::pair<int, int> size) {
    x=pos.first;
    y=pos.second;
    width=size.first;
    height=size.second;
    window=newwin(height, width, y, x);
    refresh();
    wrefresh(window);
}

void Screen::set_border(char ts, char bs, char ls, char rs, char tl, char tr, char bl, char br) {
    wborder(window, ls, rs, ts, bs, tl ,tr, bl, br);
    wrefresh(window);
}

void Screen::wrap_box(char horch, char verch) {
    box(window, verch, horch);
    wrefresh(window);
}

void Screen::draw_surf(std::pair<int, int> pos, Surface surf) {
    int xMax, yMax;
    getmaxyx(window, yMax, xMax);

    wattron(window, COLOR_PAIR(surf.color));
    
    for(int i=0;i+pos.second<=yMax && i<surf.size.second;++i)
        for(int j=0;j<surf.size.first && pos.first+j<=xMax;++j){
            mvwaddch(window, pos.second+i, pos.first+j, surf.graphic[i][j]);
        }

    wattroff(window, COLOR_PAIR(surf.color));

    refresh();
    wrefresh(window);
}

void Screen::draw_line(std::pair<int, int> point1, std::pair<int, int> point2, char ch, int color) {
    wattron(window, COLOR_PAIR(color));

    int dx=std::abs(point2.first - point1.first);
    int sx = point1.first < point2.first ? 1 : -1;
    int dy=-std::abs(point2.second - point1.second);
    int sy = point1.second < point2.second ? 1 : -1;
    int error = dx+dy;

    while(true)
    {
        mvwaddch(window, point1.second, point1.first, ch);
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

    wattroff(window, COLOR_PAIR(color));

    wrefresh(window);
}

void Screen::draw_rect(Rect rect, char grph, int color) {
    int xMax, yMax;
    getmaxyx(window, yMax, xMax);

    wattron(window, COLOR_PAIR(color));
    
    for(int i=0;i+rect.pos.second<=yMax && i<rect.size.second;++i)
    {
        mvwaddch(window, rect.pos.second+i, rect.pos.first, grph);
        if(rect.size.first + rect.pos.first - 1 <=xMax)
            mvwaddch(window, rect.pos.second+i, rect.pos.first + rect.size.first - 1, grph);
    }

    for(int i=0;i+rect.pos.first<=xMax && i<rect.size.first;++i)
    {
        mvwaddch(window, rect.pos.second, rect.pos.first+i, grph);
        if(rect.size.second + rect.pos.second - 1 <=yMax)
            mvwaddch(window, rect.pos.second + rect.size.second - 1, rect.pos.first+i, grph);
    }

    wattroff(window, COLOR_PAIR(color));

    refresh();
    wrefresh(window);
}

Surface::Surface(std::pair<int, int> sz, char sym) {
    size = sz;

    for(int i=0;i<size.second;++i)
    {
        std::string f="";
        for(int j=0;j<size.first;++j)
            f+=sym;
        graphic.push_back(f);
    }
}

void Surface::set_color(int clr) {
    color = clr;
}

int get_window_width(WINDOW * window) {
    return getmaxx(window);
}

int get_window_height(WINDOW * window) {
    return getmaxy(window);
}

void init_color_pairs() {
    init_pair(7,7,0);
    init_pair(2,2,0);
    init_pair(3,3,0);
    init_pair(4,4,0);
    init_pair(5,5,0);
    init_pair(6,6,0);
    init_pair(1,1,0);
}

Rect::Rect(std::pair<int,int> ps, std::pair<int,int> sz)
{
    pos=ps;
    size=sz;
}

Rect Rect::copy() {
    return Rect(pos, size);
}

Rect Rect::move(std::pair<int,int> offset) {
    return Rect({pos.first + offset.first, pos.second + offset.second}, size);
}

void Rect::move_ip(std::pair<int,int> offset) {
    pos.first += offset.first;
    pos.second += offset.second;
}

Rect Rect::inflate(std::pair<int,int> offset) {
    return Rect(pos, {size.first + offset.first, size.second + offset.second});
}

void Rect::inflate_ip(std::pair<int,int> offset) {
    size.first += offset.first;
    size.second += offset.second;
}