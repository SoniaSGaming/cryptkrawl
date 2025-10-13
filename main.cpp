#include <ncurses.h>
#include "engine/surface.h"
#include "engine/blitting.h"
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

    Surface srf(10, 10, '#');
    srf.set_color(1);

    Surface srf1(20, 5, '@');
    srf1.set_color(2);

    blit_surf(stdscr, 10, 15, srf);
    blit_surf(stdscr, 20, 15, srf1);

    getch();
    endwin();
}