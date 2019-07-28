//threedimensionalshape.cpp
//Name:Zhou Tian

#include "ThreeDimensionalShape.h"

#include<iostream>
using namespace std;


ThreeDimensionalShape::ThreeDimensionalShape()
{
	surfarea = 0.0;
	volume = 0.0;
}

void ThreeDimensionalShape::setSurfarea(double surfaceArea)
{
	surfarea = surfaceArea;
}

double ThreeDimensionalShape::getSurfarea() const
{
	return surfarea;
}

void ThreeDimensionalShape::setVolume(double volumeValue)
{
	volume = volumeValue;
}

double ThreeDimensionalShape::getVolume() const
{
	return volume;
}

void ThreeDimensionalShape::print3D() const
{
	cout << "Center = (" << x << "," << y << ")"
		<< " ; Surface area = " << surfarea
		<< " ; Volume = " << volume << endl;
	
}