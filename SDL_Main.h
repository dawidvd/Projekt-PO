//
//  SDL_Main.h
//  SDL DOMO
//
//

#ifndef __SDL_DOMO__SDL_Main__
#define __SDL_DOMO__SDL_Main__

#include <stdio.h>
#include <SDL2/SDL.h>
#include "Element.h"
#include <vector>

class Main_Sdl
{
private:
    SDL_Window* main_window;
    SDL_Renderer* renderer;
    void Draw() const;
    std::vector<Element*> Elementy;
    bool NeedRedraw;
    void HandleMouseDown() const;
    void HandleMouseMove();
    //return true if Event is of type quit
    bool HandleEvent(SDL_Event);
    
public:
    Main_Sdl();
    bool Loop();
    ~Main_Sdl();
};

#endif /* defined(__SDL_DOMO__SDL_Main__) */
