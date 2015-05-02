OBJS = main.cpp Button.cpp DragAndDropButton.cpp Desktop.cpp Element.cpp SDL_Main.cpp Surface.cpp Color.cpp

CC = g++

COMPILER_FLAGS = -Wall -Wextra -pedantic-errors -std=c++14 -g 

LINKER_FLAGS = -lSDL2 -lSDL2_ttf -I/usr/local/include -L/usr/local/lib

OBJ_NAME = main

all : $(OBJS)
		$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
