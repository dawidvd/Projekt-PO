#include "TextBox.h"

void TextBox::mouseClick(Main_Sdl& main)
{
	main.SetToTextInput(this);	
}

void TextBox::AddText(std::string str)
{
	text += str;
	if(surface == nullptr)
		surface = new Surface();
	surface->SetString(text);
}

void TextBox::Delete()
{
	if(text.length() > 0)
	{
		text.pop_back();
		surface->SetString(text);
	}
}
