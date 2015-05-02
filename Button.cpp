//
//  Button.cpp
//  SDL DOMO
//
//

#include "Button.h"

void Button::highlight()
{
	color = color.GetFlatColor(1);
}

void Button::unHighlight()
{
	color = color.GetFlatColor(15);
}

Button::Button(Point position,  int width,  int high) : Element(position, width, high)
{
    unHighlight();
}

Button::Button( int X,  int Y,  int width,  int high) : Button::Button(Point{X,Y}, width, high) {}
