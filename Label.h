//
//  Label.h
//  SDL DOMO
//
//

#ifndef __SDL_DOMO__Label__
#define __SDL_DOMO__Label__

#include <string>
#include "Element.h"
class Label : public Element
{
public:
	Label(std::string, int X = 0, int Y = 0, int width = 100, int high = 100);
	virtual void Draw(SDL_Renderer*) override;
private:
	std::string str;
    
};
#endif /* defined(__SDL_DOMO__Label__) */
