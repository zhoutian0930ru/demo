//homework3.cpp
//Name:Zhou Tian
//Course:16:332:503,Programming Finance
//Date of submission:2017/10/06
//Example:Using functions to perform Vector operation.
//        (Addition,Subtraction,Multiplication,Determinant,Transpose and Inverse)

#include<iostream>
using namespace std;

#include<iomanip>
using std::setw;

#include<vector>
using std::vector;

vector<int> resultArray(100);
int i, j;                               //variables used in the for loop
int row, column;                        //row and column of matrix
double detA;                            //determinant of the matrix

//inputting and displaying functions
void inputVector(vector<int>&);
void outputVector(const vector<int>&);

//6 operations
void addition(vector<int>&, vector<int>&);
void subtraction(vector<int>&, vector<int>&);
void multiplication(vector<int>&, vector<int>&);
int determinant(vector<int>&);
void transpose(vector<int>&);
void inverse(vector<int>&);

int main() {

	int choice;
	cout << "\n Menu ";
	cout << "\n choice 1 :addition";
	cout << "\n choice 2 :substraction";
	cout << "\n choice 3 :multiplication";
	cout << "\n choice 4 :determinant";
	cout << "\n choice 5 :transpose";
	cout << "\n choice 6 :inverse";
	cout << "\n choice 7 :quit";
	cout << "\n Enter your Choice:";
	cin >> choice;

	cout << "enter the number of row(1-10): ";
	cin >> row;
	cout << "enter the number of column(1-10): ";
	cin >> column;

	while (row < 1 || row > 10 || column < 1|| column > 10) {
		cout << "Please enter correct number of row and column between 1 to 10." << endl;
		cout << "enter the number of row(1-10): ";
		cin >> row;
		cout << "enter the number of column(1-10): ";
		cin >> column;
	}
	vector<int> integer1(row*column);
	vector<int> integer2(row*column);

	//Using do while() loop to ask user his choice whether he wants to quit or he want to perform another operation
	int rechoice;
	do {
		switch (choice)
		{
		case 1://Addition operation
			cout << "enter the first vector" << endl;
			inputVector(integer1);
			cout << "enter the second vector" << endl;
			inputVector(integer2);
			addition(integer1, integer2);
			outputVector(resultArray);
			break;
		case 2://Subtraction operation
			cout << "enter the first vector" << endl;
			inputVector(integer1);
			cout << "enter the second vector" << endl;
			inputVector(integer2);
			subtraction(integer1, integer2);
			outputVector(resultArray);
			break;
		case 3://Multiplication operation
			cout << "enter the first vector" << endl;
			inputVector(integer1);
			cout << "enter the second vector" << endl;
			inputVector(integer2);
			multiplication(integer1, integer2);
			outputVector(resultArray);
			break;
		case 4://Counting the determinant of matrix
			cout << "enter the vector" << endl;
			inputVector(integer1);
			if (row == 3 && column == 3) {
				cout << "The determinant of the inputting array is: " << determinant(integer1) << endl;
			}
			else
				cout << "The operation is not supported." << endl;
			break;
		case 5://Transpose operation
			inputVector(integer1);
			if (row == 3 && column == 3) {
				transpose(integer1);
				outputVector(resultArray);
			}
			else
				cout << "The operation is not supported." << endl;
			break;
		case 6://Counting the inverse matrix of the inputting matrix
			inputVector(integer1);
			if (row == 3 && column == 3) {
				detA = determinant(integer1);
				inverse(integer1);
				//inverse matrix has a double output, so cannot use the displaying function
				cout << "The output array is: " << endl;
				size_t i;
				for (i = 0; i < row*column; i++) {
					cout << setw(10) << resultArray[i] / detA;
					if ((i + 1) % column == 0)
						cout << endl;
				}		
			}
			else
				cout << "The operation is not supported." << endl;
			break;

		}

		//enter the rechoice number judge whether you want to quit or perform another operation.
		cout << "Do you want to perform another operation or quit?" << endl;
		cout << "continue = 0    quit = 1 : ";
		cin >> rechoice;
		if (rechoice == 0) {
			cout << "\n Menu ";
			cout << "\n choice 1 :addition";
			cout << "\n choice 2 :substraction";
			cout << "\n choice 3 :multiplication";
			cout << "\n choice 4 :determinant";
			cout << "\n choice 5 :transpose";
			cout << "\n choice 6 :inverse";
			cout << "\n choice 7 :quit";
			cout << "\n Enter your Choice:";
			cin >> choice;
		}
	} while (rechoice == 0);


	system("pause");

	return(0);
}

//input function(1 vector)
void inputVector(vector<int>&array)
{
	for (size_t i = 0; i < array.size(); i++) {
		cout << "array" << i + 1 << endl;
		cin >> array[i];
	}	
}

//output function(1 vector)
void outputVector(const vector<int>&array)
{
	size_t i;
	cout << "the result vector is: " << endl;
	for (i = 0; i < row*column; i++) {
		cout << setw(10) << array[i];
		if ((i + 1) % column == 0)
			cout << endl;
	}
	cout << endl;
}

//addition function(vector1 + vector2)
void addition(vector<int>&array1,vector<int>&array2)
{
	if (array1.size() == array2.size()) {
		for (i = 0; i < array1.size(); i++)
			resultArray[i] = array1[i] + array2[i];
	} 
}

//substraction function(vector1 - vector2)
void subtraction(vector<int>&array1, vector<int>&array2)
{
	if (array1.size() == array2.size()) {
		for (i = 0; i < array1.size(); i++)
			resultArray[i] = array1[i] - array2[i];
	}
}

//multiplication function(vector1 * vector2)
void multiplication(vector<int>&array1, vector<int>&array2)
{
	if (array1.size() == array2.size()) {
		for (i = 0; i < array1.size(); i++)
			resultArray[i] = array1[i] * array2[i];
	}
}

//transpose function(switch the row and column)
void transpose(vector<int>&array)
{
	int hold;
	hold = row;
	row = column;
	column = hold;
	for(i = 0; i < row; i++){
		for (j = 0; j < column; j++) {
			resultArray[i*column + j] = array[j*row + i];
		}
	}
}

//determinant function(only calculate 3*3 vector)
int determinant(vector<int>&a)
{
	int detArray;
	detArray = a[0] * a[4] * a[8] + a[1] * a[5] * a[6] + a[2] * a[3] * a[7];
	detArray = detArray - a[0] * a[5] * a[7] - a[1] * a[3] * a[8] - a[2] * a[4] * a[6];
	return detArray;
}

//inverse function(only calculate 3*3 vector)
void inverse(vector<int>&a)
{
	resultArray[0] = (a[4] * a[8] - a[5] * a[7]);
	resultArray[3] = (a[5] * a[6] - a[3] * a[8]);
	resultArray[6] = (a[3] * a[7] - a[4] * a[6]);

	resultArray[1] = (a[2] * a[7] - a[1] * a[8]);
	resultArray[4] = (a[8] * a[0] - a[6] * a[2]);
	resultArray[7] = (a[1] * a[6] - a[7] * a[0]);

	resultArray[2] = (a[1] * a[5] - a[2] * a[4]);
	resultArray[5] = (a[2] * a[3] - a[0] * a[5]);
	resultArray[8] = (a[4] * a[0] - a[1] * a[3]);
}
