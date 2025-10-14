CFLAGS=-lncurses
CC=g++
BINS=main libgamengine.so runtime_librarytest

all: $(BINS)

libgamengine.o: engine/libgamengine.cpp engine/gamengine.h
	$(CC) $(CFLAGS) -c engine/libgamengine.cpp

libgamengine.so: engine/libgamengine.cpp engine/gamengine.h
	$(CC) $(CFLAGS) -fPIC -shared -o $@ engine/libgamengine.cpp -lc

main: main.cpp engine/libgamengine.o
	$(CC) $(CFLAGS) -o $@ $^

runtime_librarytest: main.cpp
	$(CC) $(CFLAGS) -o $@ $^ -L. -lgamengine

clean:
	rm *.o *.so engine/libgamengine
