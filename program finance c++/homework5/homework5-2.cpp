//homework5-2.cpp
//Name:Zhou Tian
//Course:16:332:503,Programming Finance
//Date of submission:2017/10/12
//Example:A puzzle jump:You can move either left or right a distance equal to the number under the peg.
//                      The goal is to move to the rightmost number.

#include<iostream>
using namespace std;

#include<iomanip>
using std::setw;

//declare a function
int puzzle_jump(int, int[],int);

int main(){
	int arrayNum;             //declare the number of elements in the array
	int peg_position=0;       //declare and initialize the peg position
	int resultNum;            //output of the function

	//enter the arrayNum
	cout << "How many elements(except the end 0) you want to put in the array:" ;
	cin >> arrayNum;
	while (arrayNum < 1) {
		cout << "The quantity of array element should be positive." << endl;
		cout << "How many elements(except the end 0) you want to put in the array:";
		cin >> arrayNum;
	}

	//declare a dynamic array
	int *array = new int[arrayNum+1];

	//enter the elements of the array[],and add 0 in the end
	cout << "Please enter elements in the array.(positive)" << endl;
	for (int i = 0; i < arrayNum; i++) {
		cout << "array[" << i << "]: ";
		cin >> array[i];
		while (array[i] < 1) {
			cout << "enter again " << i << ": ";
			cin >> array[i];
		}
	}
	array[arrayNum] = 0;
	
	//display the array[]
	cout << "The result of array is:";
	for (int j = 0; j <= arrayNum; j++) {
		cout << setw(5) << array[j];
	}
	cout << endl;

	//run the function and return its result
	resultNum = puzzle_jump(arrayNum, array, peg_position);
	cout << "The result of the puzzle jump is: ";
	cout << resultNum;
	if (resultNum == 0)
		cout << " False" << endl;
	else
		cout << " True" << endl;
	
	//delete the dynamic array
	delete[] array;
	
	system("pause");

	return 0;
}

//function:puzzle_jump
int puzzle_jump(int arrayNumber, int b[],int n)
{
	int hold;          //declare variable "hold" to store the element temporarily
	int count = 0;     //declare and initialize the count variable
	
	//whether the peg reach the destination successfully
	if (n == arrayNumber)
		return 1;

	//whether the position "n" is arrived before
	if (b[n] == -1)
		return 0;
	
	//turn left
	if (b[n] < n){
		hold = b[n];
		b[n] = -1;
		count = count + puzzle_jump(arrayNumber, b, n - hold);
		b[n] = hold;
	}

	//turn right
	if (b[n] < arrayNumber + 1 - n) {
		hold = b[n];
		b[n] = -1;
		count = count + puzzle_jump(arrayNumber, b, n + hold);
	}

	return count;
}