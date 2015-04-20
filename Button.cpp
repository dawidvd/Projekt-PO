//
//  Button.cpp
//  SDL DOMO
//
//

#include "Button.h"

void Button::mouseClick(Main_Sdl&)
{
	
}

void Button::highlight()
{
    color.r = 0x2e;
    color.g = 0xcc;
    color.b = 0x71;
}

void Button::unHighlight()
{
    color.r = 0xec;
    color.g = 0xf0;
    color.b = 0xf1;
}

Button::Button(Point position,  int width,  int high) : Element(position, width, high)
{
    unHighlight();
}

Button::Button( int X,  int Y,  int width,  int high) : Button::Button(Point{X,Y}, width, high) {}
