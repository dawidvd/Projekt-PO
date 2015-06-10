#include "MoveWindowBar.h"

MoveWindowBar::MoveWindowBar(Window *window, int X, int Y, int high, int width) 
	: Button::Button(X, Y, high, width), myWindow(window){}

MoveWindowBar::MoveWindowBar(Window *window, Point point, int high, int width)
	: Button::Button(point, high, width), myWindow(window){}

void MoveWindowBar::Drag(Point point)
{
	Point delta = {startPos.x - point.x, startPos.y - point.y};
	myWindow->Move(delta);
	startPos = point;
}

void MoveWindowBar::Drop()
{
	highlight();
}

void MoveWindowBar::mouseClick(Main_Sdl& main)
{
	myWindow->PutMeOnTop();
	SDL_GetMouseState(&startPos.x, &startPos.y);
	main.GetDesktop(0).PutOnTop(this);
	main.SetToDrag(this);
	color = color.GetFlatColor(FlatColor::concrete);
}

void MoveWindowBar::Resize(double newWidth, double newHigh) 
{
	width += newWidth;
}
void MoveWindowBar::Move(Point delta)  
{
	position -= delta;
}
