#include "threedimensionalpoint.h"

ThreeDimensionalPoint::ThreeDimensionalPoint() {
	setx(0);
	sety(0);
	setz(0);
}

ThreeDimensionalPoint::ThreeDimensionalPoint(int xin, int yin, int zin) {
	setx(xin);
    sety(yin);
	setz(zin);
	//please implement this constructor to set the x, y and z values to the input parameter values
}
int ThreeDimensionalPoint::getz() {
	return z;
	//please implement this function to get the z value
}
void ThreeDimensionalPoint::setz(int zin) {
	z = zin;
	//please implement this function to set z value
}

void ThreeDimensionalPoint::addPoints(ThreeDimensionalPoint pointin) {
	setx(getx() + pointin.getx());
	sety(gety() + pointin.gety());
	setz(getz() + pointin.getz());
	//please implement this function to add the x,y and z values of point1 to values of the calling instance of the object
}