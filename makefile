OBJS = main.o game.o player.o plateform.o
cc = g++
CFLAGS = -g -Wall -c
LIBS = -lSDL2 -lSDL2_image -lSDL2_ttf
Include_Dir_SDL2 = -I/usr/include/SDL2


all : dir bin/jeu bin/test

dir:
	mkdir obj
	mkdir bin

bin/jeu : $(OBJS)
	$(cc) $(Include_Dir_SDL2) obj/main.o obj/game.o obj/player.o obj/plateform.o -o bin/jeu $(LIBS)

player.o : src/player.cpp
	$(cc) $(CFLAGS) $(Include_Dir_SDL2) src/player.cpp -o obj/player.o $(LIBS)

plateform.o : src/plateform.cpp
	$(cc) $(CFLAGS) $(Include_Dir_SDL2) src/plateform.cpp -o obj/plateform.o $(LIBS)

game.o : src/game.cpp
	$(cc) $(CFLAGS) $(Include_Dir_SDL2) src/game.cpp -o obj/game.o $(LIBS)

main.o : src/main.cpp
	$(cc) $(CFLAGS) $(Include_Dir_SDL2) src/main.cpp -o obj/main.o $(LIBS)

clean:
	rm obj/ bin/ -rf