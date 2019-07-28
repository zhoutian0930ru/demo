//circle.h
//Name:Zhou Tian

#ifndef CIRCLE_H
#define CIRCLE_H

#include "TwoDimensionalShape.h"

class Circle: public TwoDimensionalShape
{
public:
	Circle(double = 0, double = 0, double = 0);

	void setRadius(double);
	double getRadius() const;

private:
	double radius;
};

#endif
