#ifndef TEXTBOX_H_WNJTXBO8
#define TEXTBOX_H_WNJTXBO8
#include "Element.h"
#include "TextInputInterface.h"

class Element;

class TextBox: public Element, public TextInputInterface
{
public:
	using Element::Element;
    virtual void mouseClick(Main_Sdl& );
	virtual void Delete() override;
	virtual void AddText(std::string txt) override;

private:
	/* data */
	std::string text;
};

#endif /* end of include guard: TEXTBOX_H_WNJTXBO8 */
