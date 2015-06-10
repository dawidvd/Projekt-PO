#include "Window.h"

void Window::Resize(int newWidth, int newHigh)
{
	if(newWidth + width < 100)
		newWidth = 0;
	if(newHigh + high < 100)
		newHigh = 0;
    width += newWidth;
    high += newHigh;
	for(auto item: Items)
	{
		item->Resize(newWidth, newHigh);
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

Window::Window(Desktop *desktop, int X, int Y, int high, int width) : Element(X,Y,high, width), desktop (desktop)
{
	AddElement(new MoveWindowBar(this, (int) (position.x + 0.05 * width), position.y, (int) (width - 0.05 * width + 1),
								 (int) (high * 0.05 + 1)));
	AddElement(new ResizeWindowBar(this, (int) (position.x - 0.05 * width + width), (int) (position.y + high * 0.95),
								   (int) (0.05 * width + 1), (int) (high * 0.05 + 1)));
}

void Window::mouseClick(Main_Sdl&)
{
	desktop->PutOnTop(this);
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
	Element* el;
	el = dynamic_cast<Element*>(item);
	if(el)
		Elements.push_back(el);
	Items.push_back(item);
}

void Window::PutMeOnTop()
{
	desktop->PutOnTop(this);
}
