//
//  Desktop.cpp
//  SDL DOMO
//
//

#include "Desktop.h"
#include "Button.h"
#include "DragAndDropButton.h"
#include "Icon.h"
#include "Label.h"
#include "Window.h"
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
	color = color.GetFlatColor(FlatColor::silver);
	Elements.push_back(new Icon<Window>(this));
	Elements.push_back(new Label("Open window", 200, 12));
	
    //Elements.push_back(new DragAndDropButton());
}

void Desktop::AddWindow(Element* window)
{
	Elements.push_back(window);
}
