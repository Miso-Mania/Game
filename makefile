#OBJS specifies which files to compile as part of the project
OBJS = main.cpp
CC = g++
CFLAGS = -w
LINKER_FLAGS = -lSDL2 

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = Luncher

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)