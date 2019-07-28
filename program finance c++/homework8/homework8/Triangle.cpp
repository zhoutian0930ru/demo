//triangle.cpp
//Name:Zhou Tian

#include "Triangle.h"

Triangle::Triangle(double xValue, double yValue, double sideValue)
{
	setX(xValue);
	setY(yValue);
	setSide(sideValue);
}

void Triangle::setSide(double sideValue)
{
	side = (sideValue < 0.0 ? 0.0 : sideValue);
	setArea(1.73205 / 4 * side*side);
}
double Triangle::getSide() const
{
	return side;
}


