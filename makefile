all: main
main: main.cpp
	g++ main.cpp -o o.exe -lncurses -DNCURSES_STATIC 