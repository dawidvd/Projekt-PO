//
//  main.cpp
//  SDL DOMO
//
//

#include <iostream>
#include <SDL2/SDL.h>
#include "SDL_Main.h"

int main(int argc, char * argv[]) {
    Main_Sdl main;
    while (main.Loop() == false) {}
    return 0;
}
