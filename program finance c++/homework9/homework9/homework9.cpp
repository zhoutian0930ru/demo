//homework9.cpp
//Name:Zhou Tian
//Course:16:332:503,Programming Finance
//Date of submission:2017/11/10
//Example:


#include <iostream>
#include <vector>
#include <string>
#include<iomanip>

using std::setprecision;

using namespace std;

#include"TwoDayPackage.h"
#include"OvernightPackage.h"
#include"Package.h"

int main()
{
	// set floating-point number format
	cout << fixed << setprecision(2);

	cout << "Package delivery services program" << endl << endl;
	cout << "Cost per ounce for a package:  $.50/ounce" << endl
		<< "Additional cost for two day delivery:  $2.00/ounce" << endl
		<< "Additional cost for overnight delivery: $5.00/ounce" << endl << endl;

	Package package1;                 // create a Package
	TwoDayPackage package2;           // create a TwoDayPackage
	OvernightPackage package3;        // create a OvernightPackage
	double totalcost = 0.0;           // to compute the total cost of packages

    // create vector of three base-class pointers
	vector<Package*>packageVector(3);

	packageVector[0] = &package1;
	packageVector[1] = &package2;
	packageVector[2] = &package3;

	packageVector[0]->setSender("John Smith", "1 Davidson Road","Piscataway","NJ","08854");
	packageVector[0]->setReceipent("Tom Smith", "2 Davidson Road", "Piscataway", "NJ", "08854");
	packageVector[0]->setWeight(10);
	packageVector[1]->setSender("Mary Smith", "3 Davidson Road", "Piscataway", "NJ", "08854");
	packageVector[1]->setReceipent("Jennifer Smith", "4 Davidson Road", "Piscataway", "NJ", "08854");
	packageVector[1]->setWeight(5);
	packageVector[2]->setSender("John Smith", "1 Davidson Road", "Piscataway", "NJ", "08854");
	packageVector[2]->setReceipent("Mary Smith", "3 Davidson Road", "Piscataway", "NJ", "08854");
	packageVector[2]->setWeight(2);

    //using for loop to print and compute total cost
	for (int i = 0; i < packageVector.size(); i++) {
		cout << "Package " << i + 1 << ":" << endl << endl;
		packageVector[i]->print();
		totalcost = totalcost + packageVector[i]->calculateCost();
	}

	cout << "Total cost of all the packages: $" << totalcost << endl;
		
	system("pause");
	return 0;
}
