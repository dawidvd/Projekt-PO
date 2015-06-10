#ifndef WINDOWITEMINTERFACE_H_D4SLE3BF
#define WINDOWITEMINTERFACE_H_D4SLE3BF
#include "Point.h"

class WindowItemInterface
{
public:
	virtual ~WindowItemInterface (){}
	void virtual Resize(double, double) = 0;
	void virtual Move(Point) = 0;
};


#endif /* end of include guard: WINDOWITEMINTERFACE_H_D4SLE3BF */
