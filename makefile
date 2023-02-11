OBJS = main.o game.o player.o plateform.o
cc = g++
CFLAGS = -g -Wall -c
LIBS = -lSDL2 -lSDL2_image -lSDL2_ttf
Include_Dir_SDL2 = -I/usr/include/SDL2


all : dir bin/jeu bin/test

bin/jeu : $(OBJS)
	$(cc) $(Include_Dir_SDL2) objj/main.o objj/game.o objj/player.o objj/plateform.o -o bin/jeu $(LIBS)

main.o : src/main.cpp
	$(cc) $(CFLAGS) $(Include_Dir_SDL2) src/main.cpp -o objj/main.o $(LIBS)

game.o : src/game.cpp
	$(cc) $(CFLAGS) $(Include_Dir_SDL2) src/game.cpp -o objj/game.o $(LIBS)

player.o : src/player.cpp
	$(cc) $(CFLAGS) $(Include_Dir_SDL2) src/player.cpp -o objj/player.o $(LIBS)

plateform.o : src/plateform.cpp
	$(cc) $(CFLAGS) $(Include_Dir_SDL2) src/plateform.cpp -o objj/plateform.o $(LIBS)

	