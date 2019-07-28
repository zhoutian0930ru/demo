//homework3.cpp
//Name:Zhou Tian
//Course:16:332:503,Programming Finance
//Date of submission:2017/10/06
//Example:Using functions to perform Matrix operation.
//        (Addition,Subtraction,Multiplication,Determinant,Transpose and Inverse)

#include<iostream>
using namespace std;

#include<iomanip>
using std::setw;

int i, j;                               //variables used in the for loop
int row, column;                        //row and column of matrix
int firstArray[10][10] = { 0 };         //declare and initialize the inputting matrix
int secondArray[10][10] = { 0 };
int resultArray[10][10] = { 0 };        //declare and initialize the displaying matrix
double detA;                            //determinant of the matrix

//inputting and displaying functions
void inputting(int[10][10]);
void displaying(int[10][10]);

//6 operations
void addition(int[10][10],int[10][10]);
void subtraction(int[10][10],int[10][10]);
void multiplication(int[10][10],int[10][10]);
int determinant(int[10][10]);
void transpose(int[10][10]);
void inverse(int[10][10]);

int main(){

	int choice;
	int row1, column1;                  //memory of first row and column

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

	//Using do while() loop to ask user his choice whether he wants to quit or he want to perform another operation
	int rechoice;
	do {
		switch (choice) 
		{
		case 1://Addition operation
			inputting(firstArray);
			//memory the first array's dimension
			row1 = row;       
			column1 = column;
			inputting(secondArray);
			//judge whether two arrays have the same dimension
			if (row1 == row && column1 == column) {
				addition(firstArray, secondArray);
				displaying(resultArray);
			}
			else
				cout << "The operation is not supported." << endl;
			break;
		case 2://Subtraction operation
			inputting(firstArray);
			row1 = row;
			column1 = column;
			inputting(secondArray);
			if (row1 == row && column1 == column) {
				subtraction(firstArray, secondArray);
				displaying(resultArray);
			}
			else
				cout << "The operation is not supported." << endl;
			break;
		case 3://Multiplication operation
			inputting(firstArray);
			row1 = row;
			column1 = column;
			inputting(secondArray);
			if (row1 == row && column1 == column) {
				multiplication(firstArray, secondArray);
				displaying(resultArray);
			}
			else
				cout << "The operation is not supported." << endl;
			break;
		case 4://Counting the determinant of matrix
			inputting(firstArray);
			if (row == 3 && column == 3) {
				cout <<"The determinant of the inputting array is: " << determinant(firstArray) << endl;
			}
			else
				cout << "The operation is not supported." << endl;
			break;
		case 5://Transpose operation
			inputting(firstArray);
			transpose(firstArray);
			displaying(resultArray);
			break;
		case 6://Counting the inverse matrix of the inputting matrix
			inputting(firstArray);
			if (row == 3 && column == 3) {
				detA = determinant(firstArray);
				inverse(firstArray);
				//inverse matrix has a double output, so cannot the displaying function
				cout << "The output array is: " << endl; 
				for (i = 0; i < row; i++) {
					for (j = 0; j < column; j++){
						cout << setw(5) << resultArray[i][j]/detA << " ";
					}
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

//input function
void inputting(int a[10][10])
{
	//enter the row and column of the matrix
	cout << "Enter the number of rows(1-10):";
	cin >> row;
	cout << "Enter the number of columns(1-10):";
	cin >> column;
	//make sure that you have enter the correct number of row and column(1-10)
	while (row < 1 || row>10 || column < 1 || column>10) {
		cout << "Please enter the number of row and column between 1 to 10." << endl;
		cout << "Enter the number of rows(1-10):";
		cin >> row;
		cout << "Enter the number of columns(1-10):";
		cin >> column;
	}

	cout << "Please enter the value of array." << endl;
	for (i = 0; i < row; i++) {
		for (j = 0; j < column; j++) {
			cout << "row=" << i + 1 << "  column=" << j + 1 << " : ";
			cin >> a[i][j];
		}
	}
}

//display function
void displaying(int a[10][10])
{
	cout << "The output array is: " << endl;
	
	for (i = 0; i < row; i++) {
		for (j = 0; j < column; j++) {
			cout << setw(5) << a[i][j] <<" ";
		}
		cout << endl;
	}
}

//addtion function(array1+array2)
void addition(int a[10][10],int b[10][10]) 
{
	for (i = 0; i < row; i++) {
		for (j = 0; j < column; j++) {
			resultArray[i][j] = a[i][j] + b[i][j];
		}
	}
}

//subtraction function(array1-array2)
void subtraction(int a[10][10],int b[10][10])
{
	for (i = 0; i < row; i++) { 
		for (j = 0; j < column; j++) {
			resultArray[i][j] = a[i][j] - b[i][j];
		}
	}
}

//multiplication function(array1*array2)
void multiplication(int a[10][10], int b[10][10])
{
	int k;
	for (i = 0; i < row; i++) {
		for (j = 0; j < column; j++) {
			resultArray[i][j]=a[i][j]*b[i][j]
		}
	}
}

//transpose function
void transpose(int a[10][10])
{
	int hold;
	hold = row;
	row = column;
	column = hold;
	for (i = 0; i < column; i++) {
		for (j = 0; j < row; j++) {
			resultArray[i][j] = a[j][i];
		}
	}
}

//determinant function(return the detA)
int determinant(int a[10][10])
{
	int result_de;

	result_de = a[0][0] * a[1][1] * a[2][2] + a[1][0] * a[2][1] * a[0][2] + a[0][1] * a[1][2] * a[2][0];
	result_de = result_de - a[0][2] * a[1][1] * a[2][0] - a[0][1] * a[1][0] * a[2][2] - a[2][1] * a[1][2] * a[0][0];

	return result_de;
}

//inverse function
void inverse(int a[10][10])
{
	resultArray[0][0] = (a[1][1] * a[2][2] - a[1][2] * a[2][1]);
	resultArray[1][0] = (a[1][2] * a[2][0] - a[1][0] * a[2][2]);
	resultArray[2][0] = (a[1][0] * a[2][1] - a[1][1] * a[2][0]);

	resultArray[0][1] = (a[0][2] * a[2][1] - a[0][1] * a[2][2]);
	resultArray[1][1] = (a[2][2] * a[0][0] - a[2][0] * a[0][2]);
	resultArray[2][1] = (a[0][1] * a[2][0] - a[2][1] * a[0][0]);

	resultArray[0][2] = (a[0][1] * a[1][2] - a[0][2] * a[1][1]);
	resultArray[1][2] = (a[0][2] * a[1][0] - a[0][0] * a[1][2]);
	resultArray[2][2] = (a[1][1] * a[0][0] - a[0][1] * a[1][0]);
}
