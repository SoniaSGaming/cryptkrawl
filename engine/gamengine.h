#include <ncurses.h>
#include <vector>
#include <utility>
#include <string>

#ifndef _GAMENGINE_H_
#define _GAMENGINE_H_

class Rect {
    public:
        std::pair<int, int> size;
        std::pair<int, int> pos;

        Rect(std::pair<int,int> ps, std::pair<int,int> sz);

        Rect copy();

        Rect move(std::pair<int,int> offset);

        void move_ip(std::pair<int,int> offset);

        Rect inflate(std::pair<int,int> offset);

        void inflate_ip(std::pair<int,int> offset);
};

class Surface {
    public:
        std::pair<int, int> size;
        std::vector<std::string> graphic;
        int color=7;

        Surface(std::pair<int, int> sz, char sym);

        void set_color(int clr);
};

class Screen {
    public:
        int x;
        int y;
        int width;
        int height;
        WINDOW * window;

    Screen(std::pair<int, int> pos, std::pair<int, int> size);

    void set_border(char ts, char bs, char ls, char rs, char tl, char tr, char bl, char br);

    void wrap_box(char horch, char verch);

    void draw_surf(std::pair<int, int> pos, Surface surf);

    void draw_rect(Rect rect, char grph, int color=7);

    void draw_line(std::pair<int, int> point1, std::pair<int, int> point2, char ch, int color=7);

    void draw_poligon(std::vector<std::pair<int,int>> points, char ch, int color=7);

    void draw_circle(std::pair<int,int> center, int radius, char ch, int color=7);

    void draw_elipse(std::pair<int,int> center, int rx, int ry, char ch, int color=7);
};

void init_color_pairs();

int get_window_width(WINDOW * window);

int get_window_height(WINDOW * window);

#endif