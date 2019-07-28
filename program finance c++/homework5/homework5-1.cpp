//homework5-1.cpp
//Name:Zhou Tian
//Course:16:332:503,Programming Finance
//Date of submission:2017/10/12
//Example:Using recursive function to print the squares of the odd integers in descending order first
//        and then following with the squares of the even integers in ascending order
//        On input 7,it should print 49,25,9,1,4,16,36
//        On input 4,it should print 9,1,4,16

#include<iostream>
using namespace std;

//declare the function
int print_squares_recursive(int,int);

int main() {
	int count_initialized;  //declare the count variable
	int n_input;            //declare the input integer
	int maxodd;             //declare the max odd which is smaller than input integer

	//input a integer: n
	cout << "please enter a positive n: ";
	cin >> n_input;
	//using the while loop to make sure n is positive integer
	while (n_input < 1) {
		cout << "You are not enter a correct n." << endl;
		cout << "please enter a positive n: ";
		cin >> n_input;
	}
	//initialize the count variable(different between even n and odd n)
	count_initialized = 1 - n_input % 2;   
	//compute the max odd which is smaller than input integer
	maxodd = n_input - 1 + n_input % 2;
	//run the function
	print_squares_recursive(maxodd, count_initialized);

	system("pause");
	return 0;
}

//a recursive function to print a series of numbers
int print_squares_recursive(int n,int count)
{
	//while n is odd ,it is a decrease series
	if ((n % 2) == 1) {
		cout << n*n ;
		count++;
		//when meet n=1, turn the number to even
		if (n == 1){
			//when the input number is 1,there is no even number
			if (count == 1) {
				cout << endl;
				return 0;
			}
			cout << ",";   //put the "," before the function to make sure the last print without ","
			print_squares_recursive(n + 1, count);
		}			
		else {
			cout << ",";
			print_squares_recursive(n - 2, count);
		}			
	}
	//while n is even ,it is a increase series
	if ((n % 2) == 0) {
		cout << n*n ;
		count--;
		//while count variable is 1,we reach the biggist even number,then return
		if (count == 1) {
			cout << endl;
			return 0;
		}	
		else {
			cout << ",";
			print_squares_recursive(n + 2, count);
		}		
	}	
	return 0;
}