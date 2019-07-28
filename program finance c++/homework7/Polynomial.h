#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include<iostream>
using namespace std;

class Polynomial
{
public:
	Polynomial();               //constructor
	void setArray(int, int);    //set function to set private array
	//operator
	friend Polynomial operator +(const Polynomial&, const Polynomial&);//a
	friend Polynomial operator -(const Polynomial&, const Polynomial&);//b
	Polynomial& operator =(const Polynomial&);//c
	friend Polynomial operator *(const Polynomial&, const Polynomial&);//d
	Polynomial& operator +=(const Polynomial&);//e
	Polynomial& operator -=(const Polynomial&);//e
	Polynomial& operator *=(const Polynomial&);//e
	friend ostream& operator <<(ostream&, const Polynomial&);//f

private:
	//coefficient array:coe[exponent-1]=coefficient
	int coe[12];
};
#endif

