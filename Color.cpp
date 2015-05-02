#include "Color.h"


Color::Color(const unsigned short r,const unsigned short g,const unsigned short b,const unsigned short a): r(r), g(g), b(b), a(a){}

void Color::SetRendererColor(SDL_Renderer* renderer) const
{
	SDL_SetRenderDrawColor(renderer, r, g, b, a);
}

//Na podstawie http://flatuicolors.com
Color Color::GetFlatColor(unsigned int nr)
{
	switch (nr)
	{
		case 0:
			return Color{26, 188, 156};
		case 1:
			return Color{ 48, 204, 113};
		case 2:
			return Color{52, 152, 219};
		case 3:
			return Color{155, 89, 182, 25};
		case 4:
			return Color{52, 73, 94, 255};
		case 5:
			return Color{52, 73, 94, 255};
		case 6:
			return Color{22, 160, 133, 255};
		case 7:
			return Color{52, 73, 94, 255};
		case 8:
			return Color{39, 174, 96, 255};
		case 9:
			return Color{41, 128, 185, 255};
		case 10:
			return Color{142, 68, 173, 255};
		case 11:
			return Color{44, 62, 80, 255};
		case 12:
			return Color{241, 196, 15, 255};
		case 13:
			return Color{230, 126, 34, 255};
		case 14:
			return Color{231, 76, 60, 255};
		case 15:
			return Color{236, 240, 241, 255};
		case 16:
			return Color{149, 165, 166, 255};
		case 17:
			return Color{243, 156, 18, 255};
		case 18:
			return Color{211, 84, 0, 255};
		case 19:
			return Color{189, 195, 199, 255};
		default:	
			return Color{127, 140, 141};
	}
}
