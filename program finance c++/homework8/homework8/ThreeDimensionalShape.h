//threedimensionalshape.h//Name:Zhou Tian
#ifndef THREE_H
#define THREE_H

#include "shape.h"

class ThreeDimensionalShape :public shape
{
public:
	ThreeDimensionalShape();

	void setSurfarea(double);
	double getSurfarea() const;
	void setVolume(double);
	double getVolume() const;

	void print3D() const;

protected:
	double surfarea;
	double volume;
};
#endif 