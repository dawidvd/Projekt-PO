//
//  Pulpit.cpp
//  SDL DOMO
//
//

#include "Pulpit.h"
#include "Button.h"
#include <iostream>
Pulpit::Pulpit()
{
    position = Point{0, 0};
    SDL_DisplayMode CurrentDisplay ;
    for (int i = 0; i < SDL_GetNumVideoDisplays(); i++)
    {
        SDL_GetCurrentDisplayMode(i, &CurrentDisplay);
    }
    width = CurrentDisplay.w;
    high = CurrentDisplay.h;
    Elementy.push_back(new Button{24,24, 96, 48});
}

void Pulpit::Draw(SDL_Renderer* renderer) const
{
    Element::Draw(renderer);
}
