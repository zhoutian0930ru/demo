//In-Class2-2.cpp
//Name:Zhou Tian
//Course:16:332:503,Programming Finance
//Date of submission:2017/09/16
//Example:Uses "for" structures to print the following diamond shape
//  *
// ***
//*****
// ***
//  *

#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	
	// initialize variables in declarations
	int line;                    //number of total lines
	int i, j;                    //numbers used in "for" loops
	int rl;                      //line number of the top regular triangle,rl= (line + 1) / 2 

	cout << "Please enter an odd line number of the diamond shape:";
	cin >> line;

	//use a while loop to make sure that we have entered an odd number
	while (line % 2 == 0) {
		cout << "You don't enter a correct odd number,please enter an odd number:";
		cin >> line;
	}                                         


	rl = (line + 1) / 2;                                  //assign the number of top line

	//use "for" loop to enter the top regular triangle
	for (i = 1, j = 1; i <= rl; i++) {                  
		//enter the start empty space
		for (j = 1; j <= rl - i; j++)                    
			cout << " " ;
		//enter the "*"
		for (j = 1; j <= 2 * i - 1; j++)                
			cout << "*" ;

		cout <<endl;                                     //line feed to end the line
		}
	
	//use "for" loop to enter the bottom inverted triangle
	for (i = rl + 1, j = 1; i <= 2*rl - 1; i++) {        
		//enter the start empty space
		for (j = 1; j <= i - rl; j++)
			cout << " " ;
		//enter the "*"
		for (j = 1; j <= (4 * rl - 2 * i - 1); j++)
			cout << "*" ;

		cout << endl;                                    //line feed to end the line
	}

	system("pause");

	return (0);                                          //indicate program ended successfully
}

