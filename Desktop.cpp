//
//  Desktop.cpp
//  SDL DOMO
//
//

#include "Desktop.h"
#include "Button.h"
#include "DragAndDropButton.h"
#include <iostream>
Desktop::Desktop()
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
	surface->SetString("hello.bmp", 60);
	color = color.GetFlatColor(3);
    Elements.push_back(new DragAndDropButton());
    Elements.push_back(new DragAndDropButton(10, 20, 192, 96));
}
