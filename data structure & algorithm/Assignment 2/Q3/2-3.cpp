
#include<iostream>
using namespace std;

int partitioning(int, int, int, int*);

//3-way paryitioning algorithm
int main() {
	int const N = 8192;
	int a[8192];

	//create array a[8192]
	for (int i = 0; i < 1024; i++) {
		a[i] = 1;
	}
	for (int i = 1024; i < 3072; i++) {
		a[i] = 11;
	}
	for (int i = 3072; i < 7168; i++) {
		a[i] = 111;
	}
	for (int i = 7168; i < 8192; i++) {
		a[i] = 1111;
	}

	cout << partitioning(0, 8191, 111, &a[0]) << endl;


	system("pause");
	return 0;
}

int partitioning(int lo, int hi, int pivot, int *a) {
	
	if (lo == hi ) {
		return 0;
	}

	int count = 0;
	int lt = lo;
	int i = lo;
	int gt = hi;
	int temp;
	while (i < gt) {		
		if (a[i] > pivot) {
			temp = a[i];
			a[i] = a[lt];
			a[lt] = temp;
			i++;
			lo++;
			count++;
		}
		if (a[i] == pivot) {
			i++;
		}
		if (a[i] < pivot) {
			temp = a[i];
			a[i] = a[gt];
			a[gt] = temp;
			gt--;
			count++;
		}
	}

	count = count + partitioning(lo, lt, a[lo], a) + partitioning(gt, hi, a[lo], a);

	return count;
}