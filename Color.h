//
//  Color.h
//  SDL DOMO
//
//

#ifndef SDL_DOMO_Color_h
#define SDL_DOMO_Color_h
struct Color
{
    unsigned short r = 255, g = 255, b = 255, a = 255;
public:
    void SetRendererColor(SDL_Renderer* renderer) const
    {
        SDL_SetRenderDrawColor(renderer, r, g, b, a);
    }
};

#endif
