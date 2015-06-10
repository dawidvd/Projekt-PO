#ifndef SDL_DOMO_Color_h
#define SDL_DOMO_Color_h
#include <SDL2/SDL.h>

enum class FlatColor { 
	turquoise,
	emerald,
	peter_river,
	amethyst,
	wet_asphalt,
	green_sea,
	nephritis,
	belize_hole,
	wisteria,
	midnight_blue,
	sun_flower,
	carrot,
	alizarin,
	clouds,
	concrete,
	orange,
	pumpkin,
	pomegranate,
	silver,
	asbestos
};

struct Color
{
	Uint8 a;
	Uint8 b;
	Uint8 g;
	Uint8 r;
public:
	Color (Uint8 r = 0, Uint8 b = 0, Uint8 g = 0, Uint8 a = 0);
	void SetRendererColor(SDL_Renderer* renderer) const;
	static Color GetFlatColor(FlatColor );
};



#endif
