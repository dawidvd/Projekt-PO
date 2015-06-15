#ifndef CLOSEBUTTON_H_XRS0V8QU
#define CLOSEBUTTON_H_XRS0V8QU
#include "Button.h"
#include "Desktop.h"
#include <SDL_events.h>

class CloseButton:public Button
{
public:
    CloseButton(Point position, int high = 100, int width = 100)
		: Button::Button(position, high, width) 
	{
		unHighlight();
	}
    CloseButton(int X = 0,  int  Y = 0, int high = 100, int width = 100)
	: Button(X, Y, high, width)
	{
		unHighlight();
	}

	virtual void mouseClick(Main_Sdl&) override
	{
		SDL_Event e;
		e.type = SDL_QUIT;
		SDL_PushEvent(&e);
	}
	virtual ~CloseButton ()
	{}

	virtual void highlight() override
	{
		color = color.GetFlatColor(FlatColor::alizarin);
	}

	virtual void unHighlight() override
	{
		color = color.GetFlatColor(FlatColor::pomegranate);
	}
};

#endif /* end of include guard: CLOSEBUTTON_H_XRS0V8QU */
