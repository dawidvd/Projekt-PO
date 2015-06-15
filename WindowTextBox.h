#ifndef WINDOWTEXTBOX_H_XIR6SJON
#define WINDOWTEXTBOX_H_XIR6SJON
#include "TextBox.h"
#include "WindowItemInterface.h"
#include "Window.h"

class WindowTextBox: public TextBox, public WindowItemInterface
{
public:

	WindowTextBox(Window *, int X = 0, int Y = 0, int high = 0, int width = 0);
	WindowTextBox(Window *, Point, int high = 0, int width = 0);
	void virtual Resize(double, double) override;
	void virtual Move(Point) override;
	Window* myWindow;
};


#endif /* end of include guard: WINDOWTEXTBOX_H_XIR6SJON */
