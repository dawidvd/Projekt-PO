#include "Desktop.h"
#include "Button.h"
#include "Icon.h"
#include "Label.h"
#include "Window.h"
#include "CloseButton.h"

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
	Elements.push_back(new CloseButton(0, high - 144, 96, 96));
	Elements.push_back(new Label("Open window", 200, 12));
	color = Color::GetFlatColor(FlatColor::pumpkin);
    //Elements.push_back(new DragAndDropButton());
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
