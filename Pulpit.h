//
//  Pulpit.h
//  SDL DOMO
//
//

#ifndef __SDL_DOMO__Pulpit__
#define __SDL_DOMO__Pulpit__

#include <stdio.h>
#include "Element.h"

class Pulpit: public Element
{
    bool change = false;
public:
    Pulpit(SDL_Surface*);
    virtual void Draw(SDL_Renderer* renderer) const override;
};

#endif /* defined(__SDL_DOMO__Pulpit__) */
