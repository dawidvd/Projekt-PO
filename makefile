OBJS = Button.cpp Color.cpp Desktop.cpp DragAndDropButton.cpp Element.cpp Label.cpp SDL_Main.cpp Surface.cpp Window.cpp main.cpp MoveWindowBar.cpp ResizeWindowBar.cpp CloseWindow.cpp TextBox.cpp TextWindow.cpp WindowTextBox.cpp

CC = g++

COMPILER_FLAGS = -Wall -Wextra -Wconversion -pedantic-errors -std=c++14 -g 

LINKER_FLAGS = -lSDL2 -lSDL2_ttf -lSDL2_image -I/usr/local/include/SDL2 -I/usr/local/include -L/usr/local/lib

OBJ_NAME = main

all : $(OBJS)
		$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
