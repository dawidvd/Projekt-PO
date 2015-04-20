#include "Surface.h"

Surface::Surface()
{
	myTexture = nullptr;
	mySurface = nullptr;
}

void Surface::Draw(SDL_Rect* rect, SDL_Renderer* renderer)
{
	if(mySurface != nullptr && renderer != nullptr && rect != nullptr)
	{
		if(myTexture == nullptr)
			myTexture = SDL_CreateTextureFromSurface(renderer, mySurface);
		if(myTexture != nullptr)
			SDL_RenderCopy(renderer, myTexture, NULL, rect);
	}
}

Surface::~Surface()
{
	if(mySurface != nullptr)
		SDL_FreeSurface(mySurface);
	if(myTexture != nullptr)
		SDL_DestroyTexture(myTexture);
}

void Surface::AddImage(std::string string)
{
	mySurface = SDL_LoadBMP(string.c_str());
}
