#include <ncurses.h>
#include <vector>
#include <string>
#include <fstream>

#ifndef _SURFACE_H_
#define _SURFACE_H_

class Surface {
    public:
        int x;
        int y;
        int width;
        int height;
        std::vector<std::string> graphic;
        int color=7;

        Surface(int wi, int hi, char sym) {
            width=wi;
            height=hi;

            for(int i=0;i<hi;++i)
            {
                std::string f="";
                for(int j=0;j<wi;++j)
                    f+=sym;
                graphic.push_back(f);
            }
        }

        void set_color(int clr) {
            color = clr;
        }


};

#endif