//sphere.h
//Name:Zhou Tian

#ifndef SPHERE_H
#define SPHERE_H

#include "ThreeDimensionalShape.h"

class Sphere : public ThreeDimensionalShape
{
public:
	Sphere(double = 0, double = 0, double = 0);

	void setRadius(double);
	double getRadius() const;

private:
	double radius;
};

#endif
