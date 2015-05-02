//
//  Color.h
//  SDL DOMO
//
//

#ifndef SDL_DOMO_Color_h
#define SDL_DOMO_Color_h
#include <SDL2/SDL.h>
struct Color
{
	unsigned short r, g, b, a;
	public:
	Color(const unsigned short r = 255, const unsigned short g = 255, const unsigned short b = 255, const unsigned short a = 255);
	void SetRendererColor(SDL_Renderer* renderer) const;
	static Color GetFlatColor(unsigned int nr);
};

#endif
