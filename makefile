CC = g++
CFLAGS = $(shell sdl2-config --cflags)
LIBS = $(shell sdl2-config --libs) -lSDL2_image

square.o: square.cpp square.h
	$(CC) $(CFLAGS) -c square.cpp

main.o: main.cpp square.h
	$(CC) $(CFLAGS) -c main.cpp

all: main

main: main.o square.o 
	$(CC) $(CFLAGS) main.o square.o -o main $(LIBS)

clean:
	rm -f main

