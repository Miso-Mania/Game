OBJS =  obj/mainText.o obj/main.o obj/game.o obj/player.o obj/obstacle.o obj/level.o obj/score.o obj/pic.o obj/BoxFinish.o obj/tree.o obj/Case.o obj/D_Case.o obj/S_Plateform.o obj/M_Plateform.o obj/L_Plateform.o obj/DoubleJumpPort.o obj/coords.o obj/BoxCmgtGrav.o obj/mainReg.o obj/particule.o obj/enemy.o
cc = g++
CFLAGS = -g -Wall -c
LIBS = -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer 
Include_Dir_SDL2 = -I/usr/include/SDL2

all : dir bin/jeu bin/Reg bin/text

dir:
	mkdir -p obj 
	mkdir -p bin

bin/text : $(OBJS)
	$(cc) obj/mainText.o -o bin/text -lncurses

bin/jeu : $(OBJS)
	$(cc) $(Include_Dir_SDL2)  obj/main.o obj/game.o obj/player.o obj/obstacle.o obj/level.o obj/score.o obj/pic.o obj/BoxFinish.o obj/tree.o obj/Case.o obj/D_Case.o obj/S_Plateform.o obj/M_Plateform.o obj/L_Plateform.o obj/DoubleJumpPort.o obj/coords.o obj/BoxCmgtGrav.o obj/particule.o obj/enemy.o -o bin/jeu   $(LIBS)

bin/Reg : $(OBJS)
	$(cc) $(Include_Dir_SDL2)  obj/mainReg.o obj/player.o obj/level.o obj/coords.o obj/tree.o obj/obstacle.o obj/pic.o obj/BoxFinish.o obj/Case.o obj/D_Case.o obj/S_Plateform.o obj/M_Plateform.o obj/L_Plateform.o obj/DoubleJumpPort.o obj/BoxCmgtGrav.o -o bin/Reg   $(LIBS)

obj/mainText.o : src/mainText.cpp
	$(cc) $(CFLAGS) src/mainText.cpp -o obj/mainText.o $(LIBS)

obj/player.o  : src/player.cpp src/player.h src/objets/obstacle.h src/playerdirection.h src/objets/pic.h src/objets/BoxFinish.h src/objets/DoubleJumpPort.h src/coords.h src/objets/S_Plateform.h src/objets/M_Plateform.h src/objets/L_Plateform.h src/objets/BoxCmgtGrav.h
	$(cc) $(CFLAGS) $(Include_Dir_SDL2) src/player.cpp -o obj/player.o $(LIBS)

obj/obstacle.o : src/objets/obstacle.cpp src/objets/obstacle.h src/coords.h
	$(cc) $(CFLAGS) $(Include_Dir_SDL2) src/objets/obstacle.cpp -o obj/obstacle.o $(LIBS)

obj/coords.o : src/coords.cpp src/coords.h
	$(cc) $(CFLAGS) $(Include_Dir_SDL2) src/coords.cpp -o obj/coords.o $(LIBS)

obj/DoubleJumpPort.o: src/objets/DoubleJumpPort.cpp src/objets/DoubleJumpPort.h 
	$(cc) $(CFLAGS) $(Include_Dir_SDL2) src/objets/DoubleJumpPort.cpp -o obj/DoubleJumpPort.o $(LIBS)

obj/game.o : src/game.cpp src/game.h src/level.h src/player.h src/objets/obstacle.h src/objets/BoxFinish.h src/playerdirection.h src/objets/pic.h src/objets/tree.h src/objets/D_Case.h src/objets/Case.h src/json.hpp src/coords.h src/objets/S_Plateform.h src/objets/M_Plateform.h src/objets/L_Plateform.h src/objets/DoubleJumpPort.h src/objets/BoxCmgtGrav.h src/particule.h src/enemydirection.h src/enemy.h
	$(cc) $(CFLAGS) $(Include_Dir_SDL2)  src/game.cpp -o obj/game.o $(LIBS)

obj/main.o :  src/main.cpp src/game.h src/level.h src/player.h src/objets/obstacle.h src/objets/BoxFinish.h src/playerdirection.h src/objets/pic.h src/objets/tree.h src/objets/D_Case.h src/objets/Case.h src/json.hpp src/coords.h src/objets/S_Plateform.h src/objets/M_Plateform.h src/objets/L_Plateform.h src/objets/DoubleJumpPort.h src/enemydirection.h src/enemy.h
	$(cc) $(CFLAGS) $(Include_Dir_SDL2) src/main.cpp -o obj/main.o $(LIBS)

obj/level.o : src/level.cpp src/level.h src/objets/obstacle.h src/objets/pic.h src/json.hpp src/objets/BoxFinish.h src/objets/tree.h src/objets/D_Case.h src/objets/Case.h src/objets/S_Plateform.h src/objets/M_Plateform.h src/objets/L_Plateform.h src/objets/DoubleJumpPort.h src/objets/BoxCmgtGrav.h src/enemydirection.h src/enemy.h
	$(cc) $(CFLAGS) $(Include_Dir_SDL2) src/level.cpp -o obj/level.o $(LIBS)

obj/score.o : src/score.cpp src/score.h
	$(cc) $(CFLAGS) $(Include_Dir_SDL2) src/score.cpp -o obj/score.o $(LIBS)

obj/pic.o : src/objets/pic.cpp src/objets/pic.h src/coords.h
	$(cc) $(CFLAGS) $(Include_Dir_SDL2) src/objets/pic.cpp -o obj/pic.o $(LIBS)

obj/BoxFinish.o : src/objets/BoxFinish.cpp src/objets/BoxFinish.h
	$(cc) $(CFLAGS) $(Include_Dir_SDL2) src/objets/BoxFinish.cpp -o obj/BoxFinish.o $(LIBS)

obj/tree.o : src/objets/tree.cpp src/objets/tree.h
	$(cc) $(CFLAGS) $(Include_Dir_SDL2) src/objets/tree.cpp -o obj/tree.o $(LIBS)

obj/Case.o : src/objets/Case.cpp src/objets/Case.h
	$(cc) $(CFLAGS) $(Include_Dir_SDL2) src/objets/Case.cpp -o obj/Case.o $(LIBS)

obj/D_Case.o : src/objets/D_Case.cpp src/objets/D_Case.h
	$(cc) $(CFLAGS) $(Include_Dir_SDL2) src/objets/D_Case.cpp -o obj/D_Case.o $(LIBS)

obj/S_Plateform.o : src/objets/S_Plateform.cpp src/objets/S_Plateform.h src/coords.h
	$(cc) $(CFLAGS) $(Include_Dir_SDL2) src/objets/S_Plateform.cpp -o obj/S_Plateform.o $(LIBS)

obj/M_Plateform.o : src/objets/M_Plateform.cpp src/objets/M_Plateform.h src/coords.h
	$(cc) $(CFLAGS) $(Include_Dir_SDL2) src/objets/M_Plateform.cpp -o obj/M_Plateform.o $(LIBS)

obj/L_Plateform.o : src/objets/L_Plateform.cpp src/objets/L_Plateform.h src/coords.h
	$(cc) $(CFLAGS) $(Include_Dir_SDL2) src/objets/L_Plateform.cpp -o obj/L_Plateform.o $(LIBS)

obj/BoxCmgtGrav.o : src/objets/BoxCmgtGrav.cpp src/objets/BoxCmgtGrav.h src/coords.h
	$(cc) $(CFLAGS) $(Include_Dir_SDL2) src/objets/BoxCmgtGrav.cpp -o obj/BoxCmgtGrav.o $(LIBS)

obj/particule.o : src/particule.cpp src/particule.h src/coords.h
	$(cc) $(CFLAGS) $(Include_Dir_SDL2) src/particule.cpp -o obj/particule.o $(LIBS)

obj/mainReg.o: src/mainReg.cpp src/player.h src/level.h src/coords.h src/objets/obstacle.h src/objets/tree.h src/playerdirection.h src/objets/pic.h src/objets/BoxFinish.h src/objets/DoubleJumpPort.h src/objets/S_Plateform.h src/objets/M_Plateform.h src/objets/L_Plateform.h src/objets/BoxCmgtGrav.h
	$(cc) $(CFLAGS) $(Include_Dir_SDL2) src/mainReg.cpp -o obj/mainReg.o $(LIBS)

obj/enemy.o : src/enemy.cpp src/enemy.h src/enemydirection.h src/coords.h src/obj/Case.h 
	$(cc) $(CFLAGS) $(Include_Dir_SDL2) src/enemy.cpp -o obj/enemy.o $(LIBS)


clean:
	rm obj/ bin/ -rf