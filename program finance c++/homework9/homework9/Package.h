#ifndef PACKAGE_H
#define PACKAGE_H

#include <iostream>
#include <string>
using namespace std;

class Package
{
public:
	Package();
	double calculateCost();
	void print();
	void setSender(string,string,string,string,string);
	void setReceipent(string, string, string, string, string);
	void setCostperounce(double);
	void setWeight(double);
	double getCostperounce();
	double getWeight();
	
private:
	string senderName;
	string senderAddress;
	string senderCity;
	string senderState;
	string senderZipcode;

	string receipentName;
	string receipentAddress;
	string receipentCity;
	string receipentState;
	string receipentZipcode;
	
	double weight;
	double costperounce;
protected:
	string type;
};
#endif

