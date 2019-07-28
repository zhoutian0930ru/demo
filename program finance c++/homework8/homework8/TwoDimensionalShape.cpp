//twodimensionalshape.cpp
//Name:Zhou Tian

#include "TwoDimensionalShape.h"

#include<iostream>
using namespace std;


TwoDimensionalShape::TwoDimensionalShape()
{
	area = 0.0;
}

void TwoDimensionalShape::setArea(double areaValue)
{
	area = areaValue;
}

double TwoDimensionalShape::getArea() const
{
	return area;
}

void TwoDimensionalShape::print2D() const
{
	cout << "Center = (" << x << "," << y << ")"
		<< " : Area =" << area << endl;
}