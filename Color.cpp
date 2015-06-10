#include "Color.h"

Color::Color (Uint8 r, Uint8 b, Uint8 g, Uint8 a): a(a),b(b), g(g), r(r){}

void Color::SetRendererColor(SDL_Renderer* renderer) const
{
	SDL_SetRenderDrawColor(renderer, r, g, b, a);
}

Color Color::GetFlatColor(FlatColor color)
{
    switch (color) {
	case FlatColor::turquoise:
		return Color{26, 188, 156};
	case FlatColor::emerald:
		return Color{46, 204, 113};
	case FlatColor::peter_river:
		return Color{52, 152, 219};
	case FlatColor::amethyst:
		return Color{155, 89, 182};
	case FlatColor::wet_asphalt:
		return Color{52, 73, 94};
	case FlatColor::green_sea:
		return Color{22, 160, 133};
	case FlatColor::nephritis:
		return Color{39, 174, 96};
	case FlatColor::belize_hole:
		return Color{41, 128, 185};
	case FlatColor::wisteria:
		return Color{142, 68, 173};
	case FlatColor::midnight_blue:
		return Color{44, 62, 80};
	case FlatColor::sun_flower:
		return Color{241, 196, 15};
	case FlatColor::carrot:
		return Color{230, 126, 34};
	case FlatColor::alizarin:
		return Color{231, 76, 60};
	case FlatColor::clouds:
		return Color{236, 240, 241};
	case FlatColor::concrete:
		return Color{149, 165, 166};
	case FlatColor::orange:
		return Color{243, 156, 18};
	case FlatColor::pumpkin:
		return Color{211, 84, 0};
	case FlatColor::pomegranate:
		return Color{192, 57, 43};
	case FlatColor::silver:
		return Color{189, 195, 199};
	case FlatColor::asbestos:
		return Color{127, 140, 141};
    }
}
