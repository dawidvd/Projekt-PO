#ifndef TEXTWINDOW_H_J0IV73RE
#define TEXTWINDOW_H_J0IV73RE
#include "Window.h"
#include "WindowTextBox.h"

class TextWindow: public Window
{
public:
	TextWindow(Desktop *, int X = 0, int Y = 0, int high = 100, int width = 100);
};


#endif /* end of include guard: TEXTWINDOW_H_J0IV73RE */
