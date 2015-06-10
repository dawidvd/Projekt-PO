#ifndef WINDOWITEMINTERFACE_H_D4SLE3BF
#define WINDOWITEMINTERFACE_H_D4SLE3BF
#include "Point.h"

class WindowItemInterface
{
public:
	virtual ~WindowItemInterface (){}
	virtual void Resize(double, double) = 0;
	virtual void Move(Point) = 0;
};


#endif /* end of include guard: WINDOWITEMINTERFACE_H_D4SLE3BF */
