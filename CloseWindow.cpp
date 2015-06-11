#include "CloseWindow.h"
CloseWindow::CloseWindow(Window *window, int X, int Y, int high, int width) 
	: Button::Button(X, Y, high, width), myWindow(window){
		surface = new Surface();
		surface->SetImage("exitbutton.png");
	}

CloseWindow::CloseWindow(Window *window, Point point, int high, int width)
	: Button::Button(point, high, width), myWindow(window){}

void CloseWindow::mouseClick(Main_Sdl&)
{
	myWindow->Close();
}

void CloseWindow::Resize(double, double) 
{
}
void CloseWindow::Move(Point delta)  
{
	position -= delta;
}
