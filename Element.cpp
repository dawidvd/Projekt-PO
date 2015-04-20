//
//  Element.cpp
//  SDL DOMO
//
//

#include "Element.h"
Element::Element(Point position,  int width,  int high) : position(position), high(high), width(width) {}

Element::Element( int X,  int Y,  int width,  int high) : Element::Element(Point{X,Y}, high, width) { }

void Element::Draw(SDL_Renderer* renderer) const
{
    SDL_Rect temp = {position.x, position.y, width, high} ;
    color.SetRendererColor(renderer);
    SDL_RenderFillRect(renderer, &temp);
	if (surface != nullptr) 
	{
		surface->Draw(&temp, renderer);
	}
    //Rysuje elementy
    for(Element *element : Elementy)
    {
        if(element != nullptr)
            element->Draw(renderer);
    }
}

Element::~Element()
{
    for(Element* element : Elementy)
    {
       if(element != nullptr)
           delete element;
	}
	if(surface != NULL)
	delete surface;
}

bool Element::HandleMouseClick(Point position , Main_Sdl& main)
{
    if(!isPointInside(position))
       return false;
    bool handled = false;
    for(int i = Elementy.size(); i-- > 0;)
    {
		Element *element = Elementy[i];
		if(element != nullptr && element->HandleMouseClick(position, main))
		{
			handled = true;
			break;
		}
    }
    if(!handled)
        mouseClick(main);
    return true;
}

bool Element::isPointInside(Point point) const
{
    return  this->position < point && point.x - this->position.x < width && point.y - this->position.y < high;
}

bool Element::HandleMouseUp(Point position, bool &Processed)
{
    bool out = false;
    for(int i = Elementy.size(); i-- > 0;)
    {
		Element *element = Elementy[i];
        if(element != nullptr)
            if(element->HandleMouseUp(position, Processed))
				out = true;
    }
    if(!Processed && isPointInside(position))
    {
        Processed = true;
        if(!highlighted)
        {
            highlighted = true;
            highlight();
            out = true;
        }
    }
    else
    {
        if(highlighted)
        {
            highlighted = false;

            unHighlight();
            out = true;
        }
    }
    return out;
}

bool Element::PutOnTop(Element* element)
{
	if(Elementy[Elementy.size() - 1] == element)
		return true;
	unsigned int index = 0;
	for(; index < Elementy.size(); index ++)
	{
		if(Elementy[index] == element)
			break;
	}
	if(index >= Elementy.size())
		return false;
	Elementy.erase(Elementy.begin() + index);
	Elementy.push_back(element);
}
