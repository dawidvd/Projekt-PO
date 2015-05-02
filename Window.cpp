//
//  Window.cpp
//  SDL DOMO
//
//

#include "Window.h"

void Window::Resize(int newWidth, int newHigh)
{
    width += newWidth;
    high += newHigh;
	for(auto item: Items)
	{
		item->Resize(newWidth, newWidth);
	}
}

void Window::Move(Point delta)
{
	position -= delta;
	for(auto item: Items)
	{
		item->Move(delta);
	}
}

Window::Window(Desktop *destkop, int X, int Y, int high, int width) : Element(X,Y,high, width), destkop(destkop)
{
	AddElement(new MoveWindowBar(this, position.x + 0.05 * width, position.y,width - 0.05 * width, high * 0.05));
}

void Window::mouseClick(Main_Sdl&)
{
	destkop->PutOnTop(this);
}

void Window::Draw(SDL_Renderer* render)
{
	Element::Draw(render);
}

Window::~Window()
{
}

void Window::AddElement(WindowItemInterface* item)
{
	Element* el = dynamic_cast<Element*>(item);
	if(el)
		Elements.push_back(el);
	Items.push_back(item);
}

void Window::PutMeOnTop()
{
	destkop->PutOnTop(this);
}
