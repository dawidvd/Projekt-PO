//
//  Window.h
//  SDL DOMO
//
//

#ifndef __SDL_DOMO__Window__
#define __SDL_DOMO__Window__

#include "Element.h"
#include "Desktop.h"
#include "MoveWindowBar.h"
#include "WindowItemInterface.h"

class MoveWindowBar;

class Window : public Element
{
public:
	Window(Desktop *, int X = 0, int Y = 0, int high = 100, int width = 100);
	virtual ~Window();
	virtual void Draw(SDL_Renderer*) override;
    void Resize(int newWidth, int newHigh);
    void Move(Point);
	void PutMeOnTop();
protected:
	void AddElement(WindowItemInterface*);
private:
	virtual void mouseClick(Main_Sdl&) override;
	Desktop *destkop;
	using Element::Elements;
	std::vector<WindowItemInterface*> Items;
};

#endif /* defined(__SDL_DOMO__Window__) */
