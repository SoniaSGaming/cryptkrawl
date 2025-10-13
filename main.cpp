#include <ncurses/ncurses.h>
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

    Surface srf(10, 10, '#');
    srf.set_color(1, 0);

    blit_surf(stdscr, 15, 10, srf);

    getch();
    endwin();
}