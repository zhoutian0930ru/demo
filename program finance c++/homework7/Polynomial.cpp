

#include "Polynomial.h"

#include <iostream>
using namespace std;

//constructor
Polynomial::Polynomial()
{
	for (int i = 0; i < 12; i++)
		coe[i] = 0;
}

//set function
void Polynomial::setArray(int coefficient, int exponent)
{
	coe[exponent-1] = coefficient;
}

//a) Overload the addition operator (+) to add two polynomials.
Polynomial operator +(const Polynomial&a, const Polynomial&b)
{
	Polynomial add = a;
	add += b;
	
	return add;
}

//b) Overload the subtraction operator (-) to subtract two polynomials.
Polynomial operator -(const Polynomial&a, const Polynomial&b)
{
	Polynomial subtract = a;
	subtract -= b;

	return subtract;
}

//c) Overload the assignment operator (=) to assign one polynomial to another
Polynomial& Polynomial::operator =(const Polynomial&a)
{
	for (int i = 0; i < 12; i++) {
		this->coe[i] = a.coe[i];
	}
	return *this;
}

//d) Overload the multiplication operator (*) to multiply two polynomials.
Polynomial operator *(const Polynomial&a, const Polynomial&b)
{
	Polynomial multiply = a;
	multiply *= b;

	return multiply;
}

//e) Overload the addition assignment operator (+=).
Polynomial& Polynomial::operator +=(const Polynomial&a)
{
	for (int i = 0; i < 12; i++) {
		this->coe[i] += a.coe[i];
	}
	return *this;
}

//e) Overload the subtraction assignment operator (-=).
Polynomial& Polynomial::operator -=(const Polynomial&a)
{
	for (int i = 0; i < 12; i++) {
		this->coe[i] -= a.coe[i];
	}
	return *this;
}

//e) Overload the multiplication assignment operator (*=).
Polynomial& Polynomial::operator *=(const Polynomial&a)
{
	int temp[12] = { 0 };
	//using double for loop to compute the multiplication
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			temp[i + j + 1] += this->coe[i] * a.coe[j];
		}
	}
	for (int k=0; k < 12; k++) {
		this->coe[k] = temp[k];
	}
	return *this;
}

//f) Overload the output operator (<<) so that it can display the polynomials. 
ostream& operator << (ostream &output, const Polynomial &t)
{	
	//using int min to compute the minimum available exponent which has no "+" ahead of
	int min = 0;
	
	//find the min
	while (min < 12 && t.coe[min] == 0) {
		min++;
	}
	
	//if min=11 escape the for loop
	if(min==11)
		output << t.coe[min] << "x^" << min + 1;
	else
	{
		if (min == 0)
			output << t.coe[min] << "x";
		else
			output << t.coe[min] << "x^" << min + 1;

		for (int l = min + 1; l < 12; l++) {
			if (t.coe[l] != 0) {
				if (t.coe[l] < 0) {
					output << " + (" << t.coe[l] << "x^" << l + 1 << ")";
				}
				else {
					output << " + " << t.coe[l] << "x^" << l + 1;
				}
			}
		}
	}	
	return output;
}
