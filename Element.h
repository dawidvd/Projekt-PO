//
//  Element.h
//  SDL DOMO
//
//

#ifndef __SDL_DOMO__Element__
#define __SDL_DOMO__Element__

#include <stdio.h>
#include <SDL2/SDL.h>
#include "Point.h"
#include "Color.h"
#include <vector>

class Element
{
protected:
    int high, width;
    bool highlighted = false;
    Point position;
    Color color;
    std::vector<Element*> Elementy;
    virtual void mouseClick() {}
    virtual void highlight(){};
    virtual void unHighlight(){};
    bool isPointInside(Point point) const;
    //Klasa abstrakcyjna
    Element(Point positoin, int width = 100, int high = 100);
    Element( int X = 0,  int  Y = 0, int width = 100, int high = 100);
public:
    virtual void Draw(SDL_Renderer*) const;
    bool HandleMouseClick(Point position);
    bool HandleMouseUp(Point position, bool &Processed);
    ~Element();
};

#endif /* defined(__SDL_DOMO__Element__) */
