//twodimensionalshape.h//Name:Zhou Tian
#ifndef TWO_H
#define TWO_H

#include "shape.h"

class TwoDimensionalShape : public shape
{
public:
	TwoDimensionalShape();

	void setArea(double);
	double getArea() const;

	void print2D() const;

protected:
	double area;
};

#endif
