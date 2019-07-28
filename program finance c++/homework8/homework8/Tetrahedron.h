//tetrahedron.h
//Name:Zhou Tian

#ifndef TETRAHEDRON_H
#define TETRAHEDRON_H

#include "ThreeDimensionalShape.h"

class Tetrahedron : public ThreeDimensionalShape
{
public:
	Tetrahedron(double = 0, double = 0, double = 0);

	void setSide(double);
	double getSide() const;

private:
	double side;
};

#endif
