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
		{
			myTexture = SDL_CreateTextureFromSurface(renderer, mySurface);
			SDL_SetTextureBlendMode(myTexture,SDL_BLENDMODE_BLEND);
		}
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

void Surface::SetImage(std::string string)
{
	mySurface = SDL_LoadBMP(string.c_str());
}

void Surface::SetString(std::string string, unsigned int size)
{
	TTF_Font* Font = TTF_OpenFont("Font.ttf", size);
	SDL_Color color = {0,0,0, 1};
	if(Font)
	{
		mySurface = TTF_RenderText_Solid(Font, string.c_str(), color);
		TTF_CloseFont(Font);
	}
}
