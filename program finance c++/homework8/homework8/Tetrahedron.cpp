//tetrahedron.cpp
//Name:Zhou Tian

#include "Tetrahedron.h"

Tetrahedron::Tetrahedron(double xValue, double yValue, double sideValue)
{
	setX(xValue);
	setY(yValue);
	setSide(sideValue);
}

void Tetrahedron::setSide(double sideValue)
{
	side = (sideValue < 0.0 ? 0.0 : sideValue);
	setSurfarea(1.73205 * side*side);
	setVolume(1.41421 / 12 * side*side*side);
}
double Tetrahedron::getSide() const
{
	return side;
}


