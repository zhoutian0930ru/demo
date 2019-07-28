//homework8.cpp
//Name:Zhou Tian
//Course:16:332:503,Programming Finance
//Date of submission:2017/11/02
//Example:

#ifndef SHAPE_H
#define SHAPE_H

class shape
{
public:
	shape(double = 0.0, double = 0.0, double = 0.0);

	void setX(double);
	double getX() const;

	void setY(double);
	double getY() const;

	void setZ(double);
	double getZ() const;

protected:
	double x;
	double y;
	double z;
};

#endif
