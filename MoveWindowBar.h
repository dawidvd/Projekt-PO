#ifndef MOVEWINDOWBAR_H_T5U0WYXH
#define MOVEWINDOWBAR_H_T5U0WYXH
#include "Button.h"
#include "DragAndDropInterface.h"
#include "WindowItemInterface.h"
#include "Window.h"
class Window;

class MoveWindowBar: public Button, public DragAndDropInterface, public WindowItemInterface
{
public:
	MoveWindowBar(Window *, int X = 0, int Y = 0, int high = 0, int width = 0);
	MoveWindowBar(Window *, Point, int high = 0, int width = 0);
	virtual void Drag(Point) override;
	virtual void Drop() override;
	void virtual Resize(int, int) override;
	void virtual Move(Point) override;
protected:
    virtual void mouseClick(Main_Sdl&) override;
private:
	Point startPos;
	Window* myWindow;
	/* data */
};


#endif /* end of include guard: MOVEWINDOWBAR_H_T5U0WYXH */
