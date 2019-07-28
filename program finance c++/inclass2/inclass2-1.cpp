//inclass2-1.cpp
//Name:Zhou Tian
//Course:16:332:503,Programming Finance
//Date of submission:2017/09/16
//Example: Uses "for" structures to print the following triangular shape
//*
//**
//***
//****
//*****

#include<iostream>;

using std::cout;
using std::cin;
using std::endl;

int main() {
	
	// initialize variables in declarations
	int line;                  //number of line
	int i, j;                  //numbers used in "for" loops

	//enter and assign the line number "line"
	cout << "Please enter the line number of the triangular shape:";
	cin >> line;

	//each number i means a single line
	for (i = 1, j = 1; i <= line; i++) {
		//use loop to enter each line
		for (j = 1; j <= i; j++) {
			cout << "*";
		}
		
		cout << endl;          //used to end the line 
	}

	system("pause");

	return (0);                //indicate program ended successfully
}