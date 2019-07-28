//homework8.cpp
//Name:Zhou Tian
//Course:16:332:503,Programming Finance
//Date of submission:2017/11/02
//Example:

#include<iostream>
using namespace std;

#include "Circle.h"
#include "Triangle.h"
#include "Sphere.h"
#include "Tetrahedron.h"


int main()
{
	Circle c;
	Triangle tr;
	Sphere s;
	Tetrahedron te;
	int choice;
	double x, y, z;
	double radius, side;

	cout << "Please choose a shape or 0 to exit:" << endl;
	cout << "1. Circle" << endl;
	cout << "2. Triangle" << endl;
	cout << "3. Sphere" << endl;
	cout << "4. Regular Tetrahedron " << endl;
	cout << "0. Exit" << endl;
	cout << "Choice: ";
	cin >> choice;

	while (choice < 0 || choice>4)
	{
		cout << "You enter an uncorrect choice number.Please choose again:";
		cin >> choice;
	}


	while (choice != 0)
	{
		switch (choice)
		{
		case 1:
			cout << "You have chosen the circle." << endl;
			cout << endl;

			cout << "Please enter the center of the circle (x-coordinate and then y-coordinate):" << endl;
			cin >> x >> y;
			c.setX(x);
			c.setY(y);
			cout << endl;

			cout << "Please enter the radius of the circle:" << endl;
			cin >> radius;
			c.setRadius(radius);
			cout << endl;

			cout << "The circle with radius " << c.getRadius() << " that is located at (" << c.getX() << "," << c.getY() << ") has:" << endl;
			cout << "An area of " << c.getArea() << endl;
			cout << endl;
			break;
		case 2:
			cout << "You have chosen the triangle." << endl;
			cout << endl;

			cout << "Please enter the center of the triangle (x-coordinate and then y-coordinate):" << endl;
			cin >> x >> y;
			tr.setX(x);
			tr.setY(y);
			cout << endl;

			cout << "Please enter the edge length of the triangle:" << endl;
			cin >> side;
			tr.setSide(side);
			cout << endl;

			cout << "The triangle with edge length " << tr.getSide() << " that is located at (" << tr.getX() << "," << tr.getY() << ") has:" << endl;
			cout << "An area of " << tr.getArea() << endl;
			cout << endl;
			break;
		case 3:
			cout << "You have chosen the sphere." << endl;
			cout << endl;

			cout << "Please enter the center of the sphere (x-coordinate, y-coordinate and then z-coordinate):" << endl;
			cin >> x >> y >> z;
			s.setX(x);
			s.setY(y);
			s.setZ(z);
			cout << endl;

			cout << "Please enter the radius of the sphere:" << endl;
			cin >> radius;
			s.setRadius(radius);
			cout << endl;

			cout << "The sphere with radius " << s.getRadius() << " that is located at (" << s.getX() << "," << s.getY() << "," << s.getZ() << ") has:" << endl;
			cout << "Surface area of " << s.getSurfarea() << endl;
			cout << "Volume of " << s.getVolume() << endl;
			cout << endl;
			break;
		case 4:
			cout << "You have chosen the regular tetrahedron." << endl;
			cout << endl;

			cout << "Please enter the center of the regular tetrahedron (x-coordinate, y-coordinate and then z-coordinate):" << endl;
			cin >> x >> y >> z;
			te.setX(x);
			te.setY(y);
			te.setZ(z);
			cout << endl;

			cout << "Please enter the edge length of the regular tetrahedron:" << endl;
			cin >> side;
			te.setSide(side);
			cout << endl;

			cout << "The triangle with edge length " << te.getSide() << " that is located at (" << te.getX() << "," << te.getY() << "," << te.getZ() << ") has:" << endl;
			cout << "Surface area of " << te.getSurfarea() << endl;
			cout << "Volume of " << te.getVolume() << endl;
			cout << endl;
			break;
		}
		cout << "Please choose a shape or 0 to exit:" << endl;
		cout << "1. Circle" << endl;
		cout << "2. Triangle" << endl;
		cout << "3. Sphere" << endl;
		cout << "4. Regular Tetrahedron " << endl;
		cout << "0. Exit" << endl;
		cout << "Choice: ";
		cin >> choice;

		while (choice < 0 || choice>4)
		{
			cout << "You enter an uncorrect choice number.Please choose again:";
			cin >> choice;
		}
	}

	system("pause");
	return 0;
}

