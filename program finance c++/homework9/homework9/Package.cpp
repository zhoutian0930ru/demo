

#include "Package.h"
#include <iostream>
using namespace std;

Package::Package()
{
	setWeight(0.0);
	setCostperounce(0.5);
	type = "Regular Delivery";
}


double Package::calculateCost()
{
	return getWeight()*getCostperounce();
}

void Package::setSender(string s_name, string s_address, string s_city, string s_state, string s_zipcode)
{
	senderName = s_name;
	senderAddress = s_address;
	senderCity = s_city;
	senderState = s_state;
	senderZipcode = s_zipcode;
}

void Package::setReceipent(string r_name, string r_address, string r_city, string r_state, string r_zipcode)
{
	receipentName = r_name;
	receipentAddress = r_address;
	receipentCity = r_city;
	receipentState = r_state;
	receipentZipcode = r_zipcode;
}

void Package::setCostperounce(double costvalue)
{
	costperounce = (costvalue < 0.0 ? 0.0 : costvalue);
}

void Package::setWeight(double weightvalue)
{
	weight = (weightvalue < 0.0 ? 0.0 : weightvalue);
}

double Package::getCostperounce()
{
	return costperounce;
}

double Package::getWeight()
{
	return weight;
}

void Package::print()
{
	cout << "Sender:" << endl
		<< senderName << endl
		<< senderAddress << endl
		<< senderCity << "," << senderState << " " << senderZipcode << endl<<endl;
	
	cout<<"Receipent:"<<endl
		<< receipentName << endl
		<< receipentAddress << endl
		<< receipentCity << "," << receipentState << " " << receipentZipcode << endl << endl;

	cout << "Weight of package: " << getWeight() << " ounces" << endl
		<< "Type of delivery: " << type << endl
		<< "Cost of Package: $" << calculateCost() << endl << endl;
}