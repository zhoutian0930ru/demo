//homework2.cpp
//Name:Zhou Tian
//Course:16:332:503,Programming Finance
//Date of submission:2017/09/21
//Example: Using Monte Carlo methods to estimate Pi

#include <iostream>;

using namespace std;

#include <time.h>;
#include <fstream>;
#include <cstdlib>;
#include <iomanip>;

int main() {
	
	//initialize variables in declarations
	int t;
	float x,y,d;                //x,y are two random numbers from 0 to 1
	float RMax = float(32767);  //RAND_MAX
	float countd = 0.00;        //counting the number of point inside the quadrant of the circle
	float Pi;

	srand(time(0));             //the seed value for generating random numbers

	ofstream file;

	//open the file homework2.txt
	file.open("homework2.txt");
	
	//using for loop to write the values of x and y to the file
	//and count the number of point inside the quadrant of the circle by d<=1
	for (t = 1; t <= 100; t++) {
		//get the random number x and y from 0 to 1
		x = rand() / RMax;
		y = rand() / RMax;

		d = sqrt(x*x + y*y);    //d is the distence from (x,y) to (0,0)

		file << x << "," << y << "\n";  

		//count the number inside the circle
		if (d <= 1.00) {
			countd=countd+1;
		}
	}

	Pi = 4 * countd / t;
	cout <<"The estimation value of Pi is :" << Pi << endl;

	cout<<"Printed numbers to file homework2.txt\n"; 
	

	system("pause");
	
	return (0);

}