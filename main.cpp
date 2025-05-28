#include "cryptkrawl.h"
#include <ncurses.h>
#include <vector>
#include <string>

std::vector<std::string> s;

void move_player(WINDOW * win, int val, int & yp, int & xp)
{
    switch(val)
    {
        case KEY_UP:
            yp--;
            if(yp<0)
                yp=0;
            break;
        case KEY_DOWN:
            yp++;
            if(yp>=320)
                yp=319;
            break;
        case KEY_RIGHT:
            xp++;
            if(xp>=640)
                xp=639;
            break;
        case KEY_LEFT:
            xp--;
            if(xp<0)
                xp=0;
            break;
    }
}

int main()
{
    initscr();
    noecho();

    int xMax,yMax;
    getmaxyx(stdscr,yMax,xMax);

    WINDOW * main = newwin(yMax,xMax,0,0);
    refresh();

    box(main,0,0);
    wrefresh(main);

    int yp=20,xp=100;
    init_matrix(s, 320, 640,'_');
    s[yp][xp]='P';

    matrix_to_screen(main,s,yp,xp);
    wrefresh(main);

    keypad(main, true);
    int val = wgetch(main);
    while(val!='x')
    {
        s[yp][xp]='_';
        move_player(main,val,yp,xp);
        s[yp][xp]='P';
        matrix_to_screen(main,s,yp,xp);
        val=wgetch(main);
    }

    refresh();

    endwin();
    return 0;
}