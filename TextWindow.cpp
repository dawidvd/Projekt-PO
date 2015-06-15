#include "TextWindow.h"

TextWindow::TextWindow(Desktop *desktop, int X, int Y, int high, int width): Window(desktop, X, Y, high, width)
{
	AddElement(new WindowTextBox(this, 48, 48, 48, 288));
}
