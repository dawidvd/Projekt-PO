#include "Desktop.h"
#include "Button.h"
#include "Icon.h"
#include "Label.h"
#include "Window.h"

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
	auto temp = new Icon<Window>(this);
	Surface *surf = new Surface;
	surf->SetImage("addwindowicon.png");
	temp->SetSurface(surf);
	Elements.push_back(temp);
	Elements.push_back(new Label("Open window", 200, 12));
	surface = new Surface;
	surface->SetImage("MainWallpaper.png");
    //Elements.push_back(new DragAndDropButton());
}

void Desktop::AddWindow(Element* window)
{
	Elements.push_back(window);
}
