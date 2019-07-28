// IntegerSet.cpp
// Member-function definitions for class IntegerSet.

#include <iostream>
#include <iomanip>
using namespace std;

#include "IntegerSet.h"

// constructor
IntegerSet::IntegerSet()
{
	for (int i = 0; i < 101; i++) set[i] = 0;
} // end IntegerSet constructor

// input a set from the user
void IntegerSet::inputSet()
{
	int number;

	do{
		cout << "Enter an element (-1 to end): ";
		cin >> number;

		if (validEntry(number)) 
			set[number] = 1;
		else if (number != -1)
			cout << "Invalid Element\n";
	} while (number != -1); // end do...while

	cout << "Entry complete\n";
} // end function inputSet

// prints the set to the output stream
void IntegerSet::printSet() const
{
	cout << "{ ";

	for (int u = 0; u < 101; u++)
		if (set[u]) cout << u << " ";

	cout << "}" << endl;
} // end function printSet

//definition for unionOfSets
void unionOfSet(IntegerSet&au, IntegerSet&bu, IntegerSet&cu)
{
	for (int i = 0; i < 101; i++) {
		cu.set[i] = au.set[i] || bu.set[i];
	}
}

//definition for intersectionOfSets
void intersectionOfSet(IntegerSet&ai, IntegerSet&bi, IntegerSet&di)
{
	for (int i = 0; i < 101; i++) {
		di.set[i] = ai.set[i] && bi.set[i];
	}
}