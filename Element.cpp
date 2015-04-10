//
//  Element.cpp
//  SDL DOMO
//
//

#include "Element.h"
Element::Element(Point position,  int width,  int high) : position(position), high(high), width(width) {}

Element::Element( int X,  int Y,  int width,  int high) : Element::Element(Point{X,Y}, high, width) {}

void Element::Draw(SDL_Renderer* renderer) const
{
    SDL_Rect temp = {position.x, position.y, width, high} ;
    color.SetRendererColor(renderer);
    SDL_RenderFillRect(renderer, &temp);
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
}

bool Element::HandleMouseClick(Point position , DragAndDropInterface** toDrag)
{
    if(!isPointInside(position))
       return false;
    bool handled = false;
    for(Element *element: Elementy)
    {
       if(element != nullptr && element->HandleMouseClick(position, toDrag))
       {
           handled = true;
           break;
       }
    }
    if(!handled)
        mouseClick(toDrag);
    return true;
}

bool Element::isPointInside(Point point) const
{
    return  this->position < point && point.x - this->position.x < width && point.y - this->position.y < high;
}

bool Element::HandleMouseUp(Point position, bool &Processed)
{
    for(Element* element: Elementy)
    {
        if(element != nullptr)
            element->HandleMouseUp(position, Processed);
    }
    bool out = false;
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
