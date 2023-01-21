CC = g++
CFLAGS = $(shell sdl2-config --cflags)
LIBS = $(shell sdl2-config --libs) -lSDL2_image

all: main

main: main.cpp
	$(CC) $(CFLAGS) main.cpp -o main $(LIBS)

clean:
	rm -f main

