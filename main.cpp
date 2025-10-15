#include <ncurses.h>
#include "engine/gamengine.h"
#include <vector>
#include <string>
#include <fstream>

int main(){

    initscr();
    if(!has_colors()){	
        endwin();
		printf("Your terminal does not support color\n");
		exit(1);
	}
    start_color();
    init_color_pairs();

    Screen screen({0,0}, {get_window_width(stdscr),get_window_height(stdscr)});

    Rect rect({0,0}, {6,10});

    //screen.draw_rect(rect, 'a', 1);

    //Surface srf({10, 10}, '#');
    //srf.set_color(1);

    //Surface srf1({20, 5}, '@');
    //srf1.set_color(2);

    //screen.draw_surf({10, 15}, srf);
    //screen.draw_surf({20, 15}, srf1);

    /*screen.draw_line({0,0}, {5,5}, '%', 4);
    screen.draw_line({5,5}, {3, 4}, '%', 4);
    screen.draw_line({3,4}, {7,8}, '%', 4);
    screen.draw_line({7,8},{0,0}, '%', 4);*/

    screen.draw_poligon({{0,0},{20,10},{10,10}, {0,5}}, '#', 5);

    screen.draw_circle({100,20}, 20, '@', 6);

    getch();
    endwin();
}