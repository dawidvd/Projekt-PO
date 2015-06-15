#include "Desktop.h"
#include "Button.h"
#include "Icon.h"
#include "Label.h"
#include "Window.h"
#include "CloseButton.h"
#include "TextBox.h"
#include "TextWindow.h"

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
	auto temp = new Icon<Window>(this, 12, 12, 96, 96);
	Surface *surf = new Surface;
	surf->SetImage("addwindowicon.png");
	temp->SetSurface(surf);
	Elements.push_back(temp);
	Elements.push_back(new Label("Open window", 12, 108, 96, 288));
	auto temp2 = new Icon<TextWindow>(this, 12, 216, 96, 96);
	Surface *surf2 = new Surface;
	surf2->SetImage("addwindowicon.png");
	temp2->SetSurface(surf2);
	Elements.push_back(temp2);
	Elements.push_back(new Label("Open window with textbox", 12, 324, 96, 288));
	Elements.push_back(new CloseButton(12, high - 144, 96, 96));
	Elements.push_back(new Label("Quit", 12, high - 288));
	surface = new Surface();
	surface->SetImage("MainWallpaper.png");
}

void Desktop::AddWindow(Element* window)
{
	Elements.push_back(window);
}
void Desktop::Delete(Element* window)
{
	unsigned int index = 0;
	for(; index < Elements.size(); index ++)
	{
		if(Elements[index] == window)
			break;
	}
	Elements.erase(Elements.begin() + index);
	delete window;

}
