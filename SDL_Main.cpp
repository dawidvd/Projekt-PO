#include "SDL_Main.h"
#include "Desktop.h"

Main_Sdl::Main_Sdl()
{
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        exit(1);
    }
	TTF_Init();
	IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
    main_window = SDL_CreateWindow("Main", 0, 0, 1000, 800, SDL_WINDOW_SHOWN);
	SDL_SetWindowFullscreen(main_window, SDL_WINDOW_FULLSCREEN_DESKTOP);
    if(main_window == nullptr)
    {
        SDL_DestroyWindow(main_window);
        SDL_Quit();
        exit(1);
    }
    renderer = SDL_CreateRenderer(main_window, -1, SDL_RENDERER_ACCELERATED );
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    Elements.push_back(new Desktop());
    NeedRedraw = true;
    toDrag = nullptr;
}

void Main_Sdl::HandleMouseDown()
{
    Point mousePosition;
    SDL_GetMouseState(&mousePosition.x, &mousePosition.y);
    for(Element *element: Elements)
    {
        if(element->HandleMouseClick(mousePosition, *this))
           break;
    }
}

void Main_Sdl::HandleMouseMove()
{
    Point mousePosition;
    SDL_GetMouseState(&mousePosition.x, &mousePosition.y);
    if(toDrag != nullptr)
    {
        toDrag->Drag(mousePosition);
        NeedRedraw = true;
        return;
    }
    bool processed = false;
    for(Element *element: Elements)
    {
        if(element->HandleMouseUp(mousePosition, processed))
            NeedRedraw = true;
    }
}

bool Main_Sdl::HandleEvent(SDL_Event event)
{
    if(event.type == SDL_QUIT)
        return true;
    if(event.type == SDL_MOUSEBUTTONDOWN)
    {
        HandleMouseDown();
        NeedRedraw = true;
    }
    if(event.type == SDL_MOUSEBUTTONUP || event.type == SDL_MOUSEMOTION)
    {
        if(event.type == SDL_MOUSEBUTTONUP && toDrag != nullptr)
        {
			toDrag->Drop();
            toDrag = nullptr;
            NeedRedraw = true;
        }
        HandleMouseMove();
    }
    return false;
}

bool Main_Sdl::Loop()
{
    SDL_Event event;
    bool out = false;
    while (SDL_PollEvent(&event) != 0)
    {
        if(HandleEvent(event))
            out = true;
    }
    if(NeedRedraw)
    {
        Draw();
        NeedRedraw = false;
    }
    return out;
}

Main_Sdl::~Main_Sdl()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(main_window);
	TTF_Quit();
	IMG_Quit();
    SDL_Quit();
    for(Element* element : Elements)
    {
       if(element != nullptr)
           delete element;
    }
}

void Main_Sdl::Draw() const
{
    Uint8 R,G,B,A;
    SDL_GetRenderDrawColor(renderer, &R, &G, &B, &A);
    SDL_RenderClear(renderer);
    //Draw all elements
    for(Element *element : Elements)
    {
        if(element != nullptr)
            element->Draw(renderer);
    }
    SDL_SetRenderDrawColor(renderer, R, G, B, A);
    SDL_RenderPresent(renderer);
}

void Main_Sdl::SetToDrag(DragAndDropInterface* toDrag)
{
	this->toDrag = toDrag;
}

Element& Main_Sdl::GetDesktop(unsigned int index ) const
{
	if(index > Elements.size())
		return *Elements[0];
	return *Elements[index];
}

