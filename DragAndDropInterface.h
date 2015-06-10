#ifndef __SDL_DOMO__DragAndDropInterface__
#define __SDL_DOMO__DragAndDropInterface__

#include "Point.h"
class DragAndDropInterface
{
public:
    virtual void Drag(Point) = 0;
	virtual void Drop() = 0;
};
#endif /* defined(__SDL_DOMO__DragAndDropInterface__) */
