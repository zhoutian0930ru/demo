//sphere.cpp
//Name:Zhou Tian

#include "sphere.h"

Sphere::Sphere(double xValue, double yValue, double radiusValue)
{
	setX(xValue);
	setY(yValue);
	setRadius(radiusValue);
}

void Sphere::setRadius(double radiusValue)
{
	radius = (radiusValue < 0.0 ? 0.0 : radiusValue);
	setSurfarea(4 * 3.14159*radius*radius);
	setVolume(4 / 3 * 3.14159*radius*radius*radius);
}
double Sphere::getRadius() const
{
	return radius;
}


