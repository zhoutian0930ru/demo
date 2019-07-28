//circle.cpp
//Name:Zhou Tian

#include "Circle.h"

Circle::Circle(double xValue,double yValue,double radiusValue)
{
	setX(xValue);
	setY(yValue);
	setRadius(radiusValue);
}

void Circle::setRadius(double radiusValue)
{
	radius = (radiusValue < 0.0 ? 0.0 : radiusValue);
	setArea(3.14159*radius*radius);
}
double Circle::getRadius() const
{
	return radius;
}


