#include "WindowTextBox.h"

WindowTextBox::WindowTextBox(Window *window, int X, int Y, int high, int width)
	: TextBox::TextBox(X, Y, high, width), myWindow(window)
{color = Color::GetFlatColor(FlatColor::silver);}
WindowTextBox::WindowTextBox(Window *window, Point point, int high, int width) : 
	 TextBox::TextBox(point, high, width), myWindow(window){}

void WindowTextBox::Resize(double newWidth, double  newHigh)
{
	if(width + newWidth < 10)
		newWidth = 0;
	if(high + newHigh < 10)
		newHigh = 0;
	width += newWidth;
	high += newHigh;
}
void WindowTextBox::Move(Point delta)  
{
	position -= delta;
}
