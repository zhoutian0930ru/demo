#include<iostream>
#include<fstream>
using namespace std;

int main() {
	int const N = 1024;
	int a[N];
	int count;
	int increment[3] = { 7,3,1 };

	//create the data
	for (int i = 0; i < N; i++) {
		a[i] = i+1;
	}

	int point;
	int temp;


	//insertion sort
	count = 0;
	for (int j = 0; j < N; j++) {
		point = j;
		while (point > 0 && a[point] > a[point - 1]) {
			temp = a[point];
			a[point] = a[point - 1];
			a[point - 1] = temp;
			point = point - 1;
			count++;

		}
	}
	cout << "Number of comparisons (insertion sort): " << count << endl;


	//shellsort ascending
	count = 0;
	for (int incre = 0; incre < 3; incre++) {
		int h = increment[incre];
		for (int i = h; i < N; i++) {
			point = i;
			while (point-h>0 && a[point] < a[point-h]) {	
				temp = a[point];
				a[point] = a[point - h];
				a[point - h] = temp;
				point = point - h;
				count++;
			}
		}
	}
	cout << "Nnumber of comparisons (shellsort): " << count << endl;
	

	system("pause");
	return 0;
}