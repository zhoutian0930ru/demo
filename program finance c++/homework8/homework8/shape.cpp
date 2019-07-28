#include "shape.h"


shape::shape(double xValue,double yValue,double zValue)
{
	x = xValue;
	y = yValue;
	z = zValue;
}

void shape::setX(double xValue)
{
	x = xValue;
}
double shape::getX() const
{
	return x;
}

void shape::setY(double yValue)
{
	y = yValue;
}
double shape::getY() const
{
	return y;
}

void shape::setZ(double zValue)
{
	z = zValue;
}
double shape::getZ() const
{
	return z;
}

