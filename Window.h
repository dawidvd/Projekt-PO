//
//  Window.h
//  SDL DOMO
//
//

#ifndef __SDL_DOMO__Window__
#define __SDL_DOMO__Window__

#include <stdio.h>
#include "Element.h"

class Window : public Element
{
    void Resize(int newWidth, int newHigh);
};

#endif /* defined(__SDL_DOMO__Window__) */
