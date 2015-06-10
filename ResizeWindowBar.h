#ifndef RESIZEWINDOWBAR_H_OLJPQ1FI
#define RESIZEWINDOWBAR_H_OLJPQ1FI

#include "Button.h"
#include "DragAndDropInterface.h"
#include "WindowItemInterface.h"
#include "Window.h"
class Window;

class ResizeWindowBar: public Button, public DragAndDropInterface, public WindowItemInterface
{
public:
	ResizeWindowBar(Window *, int X = 0, int Y = 0, int high = 0, int width = 0);
	ResizeWindowBar(Window *, Point, int high = 0, int width = 0);
	virtual void Drag(Point) override;
	virtual void Drop() override;
	void virtual Resize(double, double) override;
	void virtual Move(Point) override;
protected:
    virtual void mouseClick(Main_Sdl&) override;
private:
	Point startPos;
	Window* myWindow;
};


#endif /* end of include guard: RESIZEWINDOWBAR_H_OLJPQ1FI */
