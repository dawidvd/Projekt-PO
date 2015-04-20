//
//  Pulpit.cpp
//  SDL DOMO
//
//

#include "Pulpit.h"
#include "Button.h"
#include "DragAndDropButton.h"
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
	surface = new Surface();
	surface->SetString("hello.bmp");
    Elementy.push_back(new DragAndDropButton());
    Elementy.push_back(new DragAndDropButton());
}

void Pulpit::Draw(SDL_Renderer* renderer) const
{
    Element::Draw(renderer);
}
