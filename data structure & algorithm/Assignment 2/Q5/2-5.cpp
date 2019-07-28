#include<iostream>
#include<fstream>
using namespace std;

int quicksort(int, int, int*);
int insertion(int, int, int*);

int main() {
	int const N = 32768;
	int a[N];
	int read[N];

	//read connect data
	ifstream data_in("data1.32768", ios::in);
	int readNumb = 0;
	if (data_in.is_open()) {
		while (!data_in.eof()) {
			data_in >> a[readNumb];
			readNumb++;
		}
	}

	

	cout << quicksort(0, N - 1, a) << endl;



	system("pause");
	return 0;
}

//ascending
int quicksort(int lo, int hi, int*a) {
	if (lo >= hi) {
		return 0;
	}

	if (hi - lo <= 7) {
		return insertion(lo, hi, a);
	}

	int count = 0;
	int pivot;
	int mid = (lo + hi) / 2;
	if (a[lo] < a[hi]) {
		if (a[hi] < a[mid]) {
			pivot = a[hi];
			a[hi] = a[lo];			
		}
		else {
			if (a[lo] < a[mid]) {
				pivot = a[mid];
				a[mid] = a[lo];
			}
			else {
				pivot = a[lo];
			}
		}

	}
	else {
		if (a[hi] > a[mid]) {
			pivot = a[hi];
			a[hi] = a[lo];
		}
		else {
			if (a[lo] > a[mid]) {
				pivot = a[mid];
				a[mid] = a[lo];
			}
			else {
				pivot = a[lo];
			}
		}
	}

	int i = lo;
	int j = hi;

	while (i < j) {
		while (a[j] > pivot && j > i) {
			j--;
		}
		a[i] = a[j];
		count++;
		while (a[i] < pivot && i < j) {
			i++;
		}
		a[j] = a[i];
		count++;
	}
	a[i] = pivot;

	count = count + quicksort(lo, i - 1, a);
	count = count + quicksort(i + 1, hi, a);

	return count;
}

//ascending
int insertion(int lo, int hi, int*a) {
	int temp;
	int count = 0;
	for (int i = lo; i <= hi; i++) {
		int k = i;
		while (k > 0 && a[k] < a[k - 1]) {
			temp = a[k];
			a[k] = a[k - 1];
			a[k - 1] = temp;
			count++;
			k--;
		}
	}
	return count;
}