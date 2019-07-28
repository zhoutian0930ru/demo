// homework1.cpp
//Find out the maximum and minimum of five entered numbers
//NAME:Zhou Tian
//RUID:181003110
//DATE OF SUBMISSION: September 15th

#include"stdafx.h"
#include<iostream>


int main()
{
        int num1, num2, num3, num4, num5;          //Declare five numbers to be entered
        int max, min;                              //Declare the maximum and minimum
	std::cout << "Please enter five numbers:\n";

	std::cout << "Enter first integer\n";
	std::cin >> num1;                      //read the first number

	std::cout << "Enter second integer\n";
	std::cin >> num2;                      //read the second number

	std::cout << "Enter third integer\n";
	std::cin >> num3;                      //read the third number

	std::cout << "Enter fourth integer\n";
	std::cin >> num4;                      //read the fourth number

	std::cout << "Enter fifth integer\n";
	std::cin >> num5;                      //read the fifth number

	max = num1;                            //assign the starting value (the first number) of maximum
	min = num1;                            //assign the starting value (the first number) of minimum

	if (num2 > max)                        //compare the second number with maximum and minimum number
		max = num2;	
	else {
		min = num2;
	}
	
	if (num3 > max)                        //compare the third number with maximum and minimum number
		max = num3;
	else {
		min = num3;
	}

	if (num4 > max)                        //compare the fourth number with maximum and minimum number
		max = num4;
	else {
		min = num4;
	}

	if (num5 > max)                        //compare the fifth number with maximum and minimum number
		max = num5;
	else {
		min = num5;
	}


	std::cout << "Maximum is " << max;    //output the derive maximum number
	std::cout << "Minimum is " << min;    //output the derive minimum number
	
	return 0; 
}

