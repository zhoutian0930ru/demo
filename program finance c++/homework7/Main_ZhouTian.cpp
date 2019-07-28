//homework7.cpp
//Name:Zhou Tian
//Course:16:332:503,Programming Finance
//Date of submission:2017/10/27
//Example:

#include<iostream>
using namespace std;

#include "Polynomial.h"

int main() {
	Polynomial a;       //the first polynomial
	Polynomial b;       //the second polynomial
	Polynomial tempc;   //a temporary polynomial used for storing the polynomial

	int term;           //number of terms in the polynomial
	int coef, expo;     //coefficient and exponent
	
	//input first polynomial
	cout << "Polynomial 1:" << endl;	
	cout << "Enter the number of polynomial 1 terms (1-6):";
	cin >> term;
	while (term < 1 || term>6) {
		cout << "Please enter a number of polynomial terms between 1 to 6 ." << endl;
		cout << "Enter the number of polynomial 1 terms (1-6):";
		cin >> term;
	}
	for (int x=0; x < term; x++) {
		cout << "Enter coefficient and exponent : ";
		cin >> coef >> expo;
		while (expo < 1 || expo>6) {
			cout << "The number of exponent should be 1-6." << endl;
			cout << "Enter coefficient and exponent : ";
			cin >> coef >> expo;
		}
		a.setArray(coef, expo);
	}
	
	//input second polynomial
	cout << "Polynomial 2:" << endl;
	cout << "Enter the number of polynomial 2 terms (1-6):";
	cin >> term;
	while (term < 1 || term>6) {
		cout << "Please enter a number of polynomial terms between 1 to 6 ." << endl;
		cout << "Enter coefficient and exponent : ";
		cin >> coef >> expo;
	}
	for (int y=0; y < term; y++) {
		cout << "Enter coefficient and exponent : ";
		cin >> coef >> expo;
		while (expo < 1 || expo>6) {
			cout << "The number of exponent should be 1-6." << endl;
			cout << "Enter coefficient and exponent : ";
			cin >> coef >> expo;
		}
		b.setArray(coef, expo);
	}

	cout << endl;
	
	//output of first &second polynomial
	cout << "First Polynomial is : ";
	cout << a << endl;
	cout << "Second Polynomial is : ";
	cout << b << endl;
	cout << endl;

	//addition operator & addition assignment operator
	cout << "Adding polynomial yields : ";
	cout << a + b << endl;
	tempc = a;
	tempc += b;
	cout << "+= the polynomial yields : ";
	cout << tempc << endl;
	cout << endl;

	//subtraction operator & subtraction assignment operator
	cout << "Subtracting polynomial yields : ";
	cout << a - b << endl;
	tempc = a;
	tempc -= b;
	cout << "-= the polynomial yields : ";
	cout << tempc << endl;
	cout << endl;

	//multiplication operator & multiplication assignment operator
	cout << "Multiplying polynomial yields : ";
	cout << a * b << endl;
	tempc = a;
	tempc *= b;
	cout << "*= the polynomial yields : ";
	cout << tempc << endl;
	cout << endl;

	system("pause");
	return 0;
}