#include "Button.h"

void Button::highlight()
{
	color = color.GetFlatColor(FlatColor::turquoise);
}

void Button::unHighlight()
{
	color = color.GetFlatColor(FlatColor::clouds);
}

Button::Button(Point position,  int width,  int high) : Element(position, width, high)
{
    unHighlight();
}

Button::Button( int X,  int Y,  int width,  int high) : Button::Button(Point{X,Y}, width, high) {}
