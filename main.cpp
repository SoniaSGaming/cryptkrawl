#include <ncurses.h>
#include "engine/surface.h"
#include "engine/drawing.h"
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

    Surface srf({10, 10}, '#');
    srf.set_color(1);

    Surface srf1({20, 5}, '@');
    srf1.set_color(2);

    draw_surf(stdscr, {10, 15}, srf);
    draw_surf(stdscr, {20, 15}, srf1);

    draw_line(stdscr, {40,20}, {50,54}, '%', 4);
    draw_line(stdscr, {40,20}, {100, 15}, '%', 3);

    getch();
    endwin();
}