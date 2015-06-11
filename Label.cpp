#include "Label.h"

Label::Label(std::string str, int X, int Y, int width, int high) : Element(X, Y, width, high), str(str)
{
	color.a = 0;
	surface = new Surface();
	surface->SetString(str, 40);
}

void Label::Draw(SDL_Renderer* renderer)
{
    SDL_Rect temp = {position.x, position.y, width, high} ;
    color.SetRendererColor(renderer);
	if (surface != nullptr) 
	{
		surface->Draw(&temp, renderer);
	}
    for(Element *element : Elements)
    {
        if(element != nullptr)
            element->Draw(renderer);
    }

}
