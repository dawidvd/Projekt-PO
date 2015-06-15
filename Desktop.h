#ifndef __SDL_DOMO__Desktop__
#define __SDL_DOMO__Desktop__

#include "Element.h"

class Desktop: public Element
{
public:
    Desktop();
	void AddWindow(Element* window);
	void Delete(Element* window);
    virtual void mouseClick(Main_Sdl& ) override {}
};

#endif /* defined(__SDL_DOMO__Desktop__) */
