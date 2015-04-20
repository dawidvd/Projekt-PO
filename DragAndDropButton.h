//
//  DragAndDropButton.h
//  SDL DOMO
//
//  Created by Dawid Hajda on 10.04.2015.
//  Copyright (c) 2015 Dawid Hajda. All rights reserved.
//

#ifndef __SDL_DOMO__DragAndDropButton__
#define __SDL_DOMO__DragAndDropButton__

#include "Button.h"
#include "DragAndDropInterface.h"
class DragAndDropButton: public Button, public DragAndDropInterface
{
private:
    Point startPos;
protected:
    virtual void mouseClick(Main_Sdl&) override;
public:
    virtual void Drag(Point) override;
	virtual void Drop() override;
    DragAndDropButton();
    
};
#endif /* defined(__SDL_DOMO__DragAndDropButton__) */
