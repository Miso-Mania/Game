OBJS = obj/main.o obj/game.o obj/player.o obj/obstacle.o obj/level.o obj/score.o obj/pic.o obj/BoxFinish.o
cc = g++
CFLAGS = -g -Wall -c
LIBS = -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -lnlohmann_json
Include_Dir_SDL2 = -I/usr/include/SDL2
Include_Dir_JSON = -I./thirdparty/json-3.11.2/single_include/nlohmann


all : dir bin/jeu

dir:
	mkdir -p obj 
	mkdir -p bin

bin/jeu : $(OBJS)
	$(cc) $(Include_Dir_SDL2) $(Include_Dir_JSON) obj/main.o obj/game.o obj/player.o obj/obstacle.o obj/level.o obj/score.o obj/pic.o -o bin/jeu obj/BoxFinish.o $(LIBS)

obj/player.o  : src/player.cpp src/player.h src/objets/obstacle.h src/playerdirection.h src/objets/pic.h
	$(cc) $(CFLAGS) $(Include_Dir_SDL2) src/player.cpp -o obj/player.o $(LIBS)

obj/obstacle.o : src/objets/ src/objets/obstacle.h
	$(cc) $(CFLAGS) $(Include_Dir_SDL2) src/objets/obstacle.cpp -o obj/obstacle.o $(LIBS)

obj/game.o : src/game.cpp src/game.h src/level.h src/player.h src/objets/obstacle.h src/playerdirection.h src/objets/pic.h
	$(cc) $(CFLAGS) $(Include_Dir_SDL2) $(Include_Dir_JSON) src/game.cpp -o obj/game.o $(LIBS)

obj/main.o : src/main.cpp src/game.h src/level.h src/player.h src/objets/obstacle.h src/playerdirection.h src/objets/pic.h
	$(cc) $(CFLAGS) $(Include_Dir_SDL2) src/main.cpp -o obj/main.o $(LIBS)

obj/level.o : src/level.cpp src/level.h src/objets/obstacle.h src/objets/pic.h
	$(cc) $(CFLAGS) $(Include_Dir_SDL2) $(Include_Dir_JSON) src/level.cpp -o obj/level.o $(LIBS)

obj/score.o : src/score.cpp src/score.h
	$(cc) $(CFLAGS) $(Include_Dir_SDL2) src/score.cpp -o obj/score.o $(LIBS)

obj/pic.o : src/objets/pic.cpp src/objets/pic.h
	$(cc) $(CFLAGS) $(Include_Dir_SDL2) src/objets/pic.cpp -o obj/pic.o $(LIBS)

obj/BoxFinish.o : src/objets/BoxFinish.cpp src/objets/BoxFinish.h
	$(cc) $(CFLAGS) $(Include_Dir_SDL2) src/objets/BoxFinish.cpp -o obj/BoxFinish.o $(LIBS)

clean:
	rm obj/ bin/ -rf