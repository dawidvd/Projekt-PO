//
//  Button.h
//  SDL DOMO
//
//

#ifndef __SDL_DOMO__Button__
#define __SDL_DOMO__Button__

#include <stdio.h>
#include "Element.h"
class Button : public Element
{
protected:
    virtual void highlight() override;
    virtual void unHighlight() override;
    virtual void mouseClick() override;
    
public:
    Button(Point positoin, int high = 100, int width = 100);
    Button( int X = 0,  int  Y = 0, int high = 100, int width = 100);
};
#endif /* defined(__SDL_DOMO__Button__) */
