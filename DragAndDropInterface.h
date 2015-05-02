//
//  DragAndDropInterface.h
//  SDL DOMO
//
//  Created by Dawid Hajda on 10.04.2015.
//  Copyright (c) 2015 Dawid Hajda. All rights reserved.
//

#ifndef __SDL_DOMO__DragAndDropInterface__
#define __SDL_DOMO__DragAndDropInterface__

#include "Point.h"
class DragAndDropInterface
{
protected:
    DragAndDropInterface(){};
public:
    virtual void Drag(Point) = 0;
	virtual void Drop() = 0;
};
#endif /* defined(__SDL_DOMO__DragAndDropInterface__) */
