#ifndef __SDL_DOMO__Surface__
#define __SDL_DOMO__Surface__
#include <SDL2/SDL.h>
#include <SDL_ttf.h>
#include <SDL_Image.h>
#include <string>

class Surface
{
	SDL_Texture *myTexture;
	SDL_Surface *mySurface;
public:
	Surface();
	void Draw(SDL_Rect*, SDL_Renderer*);
	~Surface();
	void SetImage(std::string);
	void SetString (std::string, int i = 14);

};
#endif /* defined(__SDL_DOMO__Surface__) */
