#ifndef __SDL_DOMO__SDL_Main__
#define __SDL_DOMO__SDL_Main__

#include <SDL2/SDL.h>
#include <SDL_image.h>
#include "Element.h"
#include <vector>
#include "DragAndDropInterface.h"   

class Element;
class Main_Sdl
{
private:
    SDL_Window* main_window;
    SDL_Renderer* renderer;
    std::vector<Element*> Elements;
    bool NeedRedraw;
    void Draw() const;
    void HandleMouseDown();
    void HandleMouseMove();
    //return true if Event is of type quit
    bool HandleEvent(SDL_Event);
    DragAndDropInterface* toDrag;
    
public:
    Main_Sdl();
    bool Loop();
    ~Main_Sdl();
	void SetToDrag(DragAndDropInterface* toDrag);
	Element& GetDesktop(unsigned int index = 0) const;

};

#endif /* defined(__SDL_DOMO__SDL_Main__) */
