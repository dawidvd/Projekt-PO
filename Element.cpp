#include "Element.h"

Element::Element(Point position,  int width,  int high) : high(high), width(width) ,position(position), color({255, 255, 255})
{
	surface = nullptr;
}

Element::Element( int X,  int Y,  int width,  int high) : Element::Element(Point{X,Y}, high, width)
{ }

void Element::Draw(SDL_Renderer* renderer) 
{
    SDL_Rect temp = {position.x, position.y, width, high} ;
    color.SetRendererColor(renderer);
    SDL_RenderFillRect(renderer, &temp);
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

Element::~Element()
{
    for(Element* element : Elements)
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
    for(unsigned long i = Elements.size(); i-- > 0;)
    {
		Element *element = Elements[i];
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
    for(unsigned long i = Elements.size(); i-- > 0;)
    {
		Element *element = Elements[i];
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
	if(Elements[Elements.size() - 1] == element)
		return true;
	unsigned int index = 0;
	for(; index < Elements.size(); index ++)
	{
		if(Elements[index] == element)
			break;
	}
	if(index >= Elements.size())
		return false;
	Elements.erase(Elements.begin() + index);
	Elements.push_back(element);
	return true;
}

void Element::SetSurface(Surface *&surf)
{
	surface = surf;
	surf = nullptr;
}
