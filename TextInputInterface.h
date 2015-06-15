#ifndef TEXTINPUTINTERFACE_H_T8XD7PEB
#define TEXTINPUTINTERFACE_H_T8XD7PEB

#include <string>

class TextInputInterface
{
public:
	virtual void Delete() = 0;
	virtual void AddText(std::string) = 0;
	virtual ~TextInputInterface (){}
};


#endif /* end of include guard: TEXTINPUTINTERFACE_H_T8XD7PEB */
