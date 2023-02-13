OBJS = main.o game.o player.o obstacle.o level.o playerdirection.o screen.o
cc = g++
CFLAGS = -g -Wall -c
LIBS = -lSDL2 -lSDL2_image -lSDL2_ttf
Include_Dir_SDL2 = -I/usr/include/SDL2


all : dir bin/jeu

dir:
	mkdir obj
	mkdir bin

bin/jeu : $(OBJS)
	$(cc) $(Include_Dir_SDL2) obj/main.o obj/game.o obj/player.o obj/obstacle.o obj/level.o obj/playerdirection.o obj/screen.o -o bin/jeu $(LIBS)

player.o  : src/player.cpp
	$(cc) $(CFLAGS) $(Include_Dir_SDL2) src/player.cpp -o obj/player.o $(LIBS)

obstacle.o : src/obstacle.cpp
	$(cc) $(CFLAGS) $(Include_Dir_SDL2) src/obstacle.cpp -o obj/obstacle.o $(LIBS)

game.o : src/game.cpp
	$(cc) $(CFLAGS) $(Include_Dir_SDL2) src/game.cpp -o obj/game.o $(LIBS)

main.o : src/main.cpp
	$(cc) $(CFLAGS) $(Include_Dir_SDL2) src/main.cpp -o obj/main.o $(LIBS)

level.o : src/level.cpp
	$(cc) $(CFLAGS) $(Include_Dir_SDL2) src/level.cpp -o obj/level.o $(LIBS)

screen.o : src/screen.cpp
	$(cc) $(CFLAGS) $(Include_Dir_SDL2) src/screen.cpp -o obj/screen.o $(LIBS)

playerdirection.o : src/player.cpp
	$(cc) $(CFLAGS) $(Include_Dir_SDL2) src/player.cpp -o obj/playerdirection.o $(LIBS)
clean:
	rm obj/ bin/ -rf