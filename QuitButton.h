#ifndef QUITBUTTON_H_CG9VD3Y7
#define QUITBUTTON_H_CG9VD3Y7
#include "Button.h"
#include "Desktop.h"

class CloseButton:public Button
{
public:
    CloseButton(Desktop *desktop, Point position, int high = 100, int width = 100)
		: Button::Button(position, high, width), desktop (desktop) 
	{
			unHighlight();
	}
    CloseButton(Desktop *desktop,  int X = 0,  int  Y = 0, int high = 100, int width = 100)
	: Button(X, Y, high, width), desktop (desktop)
	{
			unHighlight();
	}

	virtual void mouseClick(Main_Sdl&) override
	{
		SDL_PushEvent(SDL_QuitEvent);
	}
	virtual ~Icon ()
	{}

	virtual void unHighlight() override
	{
		color = color.GetFlatColor(FlatColor::alizarin);
	}

private:
	/* data */
	Desktop *desktop;
};

#endif /* end of include guard: QUITBUTTON_H_CG9VD3Y7 */
