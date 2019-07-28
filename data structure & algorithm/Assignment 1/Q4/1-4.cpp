#include<iostream>
#include<algorithm>
#include<vector>
#include<fstream>
#include<time.h>
using namespace std;

int main() {
	int const N = 8192;
	double a[N];
	double minValue, maxValue;
	int minNum, maxNum;
	double gap;
	int count = 0;

	clock_t start, finish;
	double totaltime;

	cout << "Size of data: " << N << endl;

	//read the data from txt and store it to vector
	ifstream data_in("8192int.txt", ios::in);

	if (data_in.is_open()) {
		while (!data_in.eof()) {
			data_in >> a[count];
			//cout << "yes" << endl;
			count++;
		}
	}

	minValue = a[0];
	maxValue = a[0];
	minNum = 0;
	maxNum = 0;
	start = clock();
	for (int i = 0; i < N; i++) {
		if (a[i] < minValue) {
			minValue = a[i];
			minNum = i;
		}
		else {
			if (a[i] > maxValue) {
				maxValue = a[i];
				maxNum = i;
			}

		}			
	}
	gap = maxValue - minValue;
	finish = clock();
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "totaltime: " << totaltime << endl;


	cout << "The min is :" << minNum << ", " << minValue << endl;
	cout << "The max is :" << maxNum << ", " << maxValue << endl;

	system("pause");
	return 0;
}