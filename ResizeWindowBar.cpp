#include "ResizeWindowBar.h"
ResizeWindowBar::ResizeWindowBar(Window *window, int X, int Y, int high, int width) 
	: Button::Button(X, Y, high, width), myWindow(window){}

ResizeWindowBar::ResizeWindowBar(Window *window, Point point, int high, int width)
	: Button::Button(point, high, width), myWindow(window){}

void ResizeWindowBar::Drag(Point point)
{
	Point delta = {startPos.x - point.x, startPos.y - point.y};
	myWindow->Resize(-delta.x, -delta.y);
	startPos = point;
}

void ResizeWindowBar::Drop()
{
	highlight();
}

void ResizeWindowBar::mouseClick(Main_Sdl& main)
{
	myWindow->PutMeOnTop();
	SDL_GetMouseState(&startPos.x, &startPos.y);
	main.GetDesktop(0).PutOnTop(this);
	main.SetToDrag(this);
	color = color.GetFlatColor(FlatColor::concrete);
}

void ResizeWindowBar::Resize(double newWidth, double newHigh) 
{
	position.x += newWidth;
	position.y += newHigh;
}
void ResizeWindowBar::Move(Point delta)  
{
	position -= delta;
}
