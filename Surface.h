//
//
//  Surface.h
//  SDL DOMO
//
//

#ifndef __SDL_DOMO__Surface__
#define __SDL_DOMO__Surface__
#include <SDL2/SDL.h>
#include <string>

class Surface
{
	SDL_Texture* myTexture;
	SDL_Surface* mySurface;
public:
	Surface();
	void Draw(SDL_Rect*, SDL_Renderer*);
	~Surface();
	void AddImage(std::string);

};
#endif /* defined(__SDL_DOMO__Surface__) */
