#ifndef CLOSEWINDOW_H_BQEPCTXK
#define CLOSEWINDOW_H_BQEPCTXK
#include "Button.h"
#include "WindowItemInterface.h"
#include "Window.h"
class CloseWindow:public Button,  public WindowItemInterface
{
public:
	CloseWindow(Window *, int X = 0, int Y = 0, int high = 0, int width = 0);
	CloseWindow(Window *, Point, int high = 0, int width = 0);
	void virtual Resize(double, double) override;
	void virtual Move(Point) override;
protected:
    virtual void mouseClick(Main_Sdl&) ;
private:
	Window* myWindow;
};


#endif /* end of include guard: CLOSEWINDOW_H_BQEPCTXK */
