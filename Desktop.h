//
//  Desktop.h
//  SDL DOMO
//
//

#ifndef __SDL_DOMO__Desktop__
#define __SDL_DOMO__Desktop__

#include "Element.h"

class Desktop: public Element
{
public:
    Desktop();
	void AddWindow(Element* window);
};

#endif /* defined(__SDL_DOMO__Desktop__) */
