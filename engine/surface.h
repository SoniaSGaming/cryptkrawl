#include <ncurses.h>
#include <vector>
#include <string>
#include <fstream>
#include <utility>

#ifndef _SURFACE_H_
#define _SURFACE_H_

class Surface {
    public:
        std::pair<int, int> size;
        std::vector<std::string> graphic;
        int color=7;

        Surface(std::pair<int, int> sz, char sym) {
            size = sz;

            for(int i=0;i<size.second;++i)
            {
                std::string f="";
                for(int j=0;j<size.first;++j)
                    f+=sym;
                graphic.push_back(f);
            }
        }

        void set_color(int clr) {
            color = clr;
        }


};

#endif
