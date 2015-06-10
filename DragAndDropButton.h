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
   using Button::Button; 
};
#endif /* defined(__SDL_DOMO__DragAndDropButton__) */
