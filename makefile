OBJS = obj/main.o obj/game.o obj/player.o obj/obstacle.o obj/level.o obj/score.o
cc = g++
CFLAGS = -g -Wall -c
LIBS = -lSDL2 -lSDL2_image -lSDL2_ttf
Include_Dir_SDL2 = -I/usr/include/SDL2


all : dir bin/jeu

dir:
	mkdir -p obj 
	mkdir -p bin

bin/jeu : $(OBJS)
	$(cc) $(Include_Dir_SDL2) obj/main.o obj/game.o obj/player.o obj/obstacle.o obj/level.o obj/score.o -o bin/jeu $(LIBS)

obj/player.o  : src/player.cpp src/player.h src/obstacle.h src/playerdirection.h
	$(cc) $(CFLAGS) $(Include_Dir_SDL2) src/player.cpp -o obj/player.o $(LIBS)

obj/obstacle.o : src/obstacle.cpp src/obstacle.h
	$(cc) $(CFLAGS) $(Include_Dir_SDL2) src/obstacle.cpp -o obj/obstacle.o $(LIBS)

obj/game.o : src/game.cpp src/game.h src/level.h src/player.h src/obstacle.h src/playerdirection.h
	$(cc) $(CFLAGS) $(Include_Dir_SDL2) src/game.cpp -o obj/game.o $(LIBS)

obj/main.o : src/main.cpp src/game.h src/level.h src/player.h src/obstacle.h src/playerdirection.h
	$(cc) $(CFLAGS) $(Include_Dir_SDL2) src/main.cpp -o obj/main.o $(LIBS)

obj/level.o : src/level.cpp src/level.h src/obstacle.h
	$(cc) $(CFLAGS) $(Include_Dir_SDL2) src/level.cpp -o obj/level.o $(LIBS)

obj/score.o : src/score.cpp src/score.h
	$(cc) $(CFLAGS) $(Include_Dir_SDL2) src/score.cpp -o obj/score.o $(LIBS)

clean:
	rm obj/ bin/ -rf