#ifndef ICON_H_MK1ODCDT
#define ICON_H_MK1ODCDT
#include "Button.h"
#include "Desktop.h"

template < typename type>
class Icon:public Button
{
public:
    Icon(Desktop *destkop, Point positoin, int high = 100, int width = 100) 	
		: Button::Button(positoin, high, width), destkop(destkop) {}
    Icon(Desktop *destkop,  int X = 0,  int  Y = 0, int high = 100, int width = 100)
	: Button(X, Y, high, width), destkop(destkop) {}

	virtual void mouseClick(Main_Sdl&) override
	{
		type *window = new type(destkop, 12, 12, 256, 456);
		destkop->AddWindow(window);
	}
	virtual ~Icon ()
	{}

private:
	/* data */
	Desktop *destkop;
};

#endif /* end of include guard: ICON_H_MK1ODCDT */
