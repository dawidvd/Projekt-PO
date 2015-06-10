#ifndef ICON_H_MK1ODCDT
#define ICON_H_MK1ODCDT
#include "Button.h"
#include "Desktop.h"

template < typename type>
class Icon:public Button
{
public:
    Icon(Desktop *desktop, Point position, int high = 100, int width = 100)
		: Button::Button(position, high, width), desktop (desktop) {}
    Icon(Desktop *desktop,  int X = 0,  int  Y = 0, int high = 100, int width = 100)
	: Button(X, Y, high, width), desktop (desktop) {}

	virtual void mouseClick(Main_Sdl&) override
	{
		type *window = new type(desktop, 12, 12, 256, 456);
		desktop->AddWindow(window);
	}
	virtual ~Icon ()
	{}

private:
	/* data */
	Desktop *desktop;
};

#endif /* end of include guard: ICON_H_MK1ODCDT */
