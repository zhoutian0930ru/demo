//triangle.h
//Name:Zhou Tian

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "TwoDimensionalShape.h"

class Triangle : public TwoDimensionalShape
{
public:
	Triangle(double = 0, double = 0, double = 0);

	void setSide(double);
	double getSide() const;

private:
	double side;
};

#endif
