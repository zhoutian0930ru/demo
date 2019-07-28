#include<iostream>
#include<fstream>
using namespace std;

int sort(int, int, int*, int*);
int merge(int, int, int, int*, int*);

int main() {
	int const N=32768;
	int a[N];
	int b[N];
	int temp[N] = {0};
	int read[N];
	int index[N + 1] = {0};
	int distance = 0;
	int count = 0;

	//read connect data
	ifstream data_ina("data0.32768", ios::in);
	int readNumb = 0;
	if (data_ina.is_open()) {
		while (!data_ina.eof()) {
			data_ina >> a[readNumb];
			readNumb++;
		}
	}

	ifstream data_inb("data1.32768", ios::in);
	readNumb = 0;
	if (data_inb.is_open()) {
		while (!data_inb.eof()) {
			data_inb >> read[readNumb];
			readNumb++;
		}
	}


	for (int i = 0; i < N; i++) {
		index[a[i]] = i;
		b[i] = read[i];
	}

	for (int j = 0; j < N; j++) {
		int temp;
		temp = index[b[j]];
		for (int k = j; k < N; k++) {
			if (index[b[k]] < index[b[j]]) {
				distance++;
			}
			count++;
		}
	}

	cout << "distance: " << distance << endl;
	cout << "number of comparison: " << count << endl;

	//mergesort
	cout << "For mergesort" << endl;
	for (int i = 0; i < N; i++) {
		b[i] = read[i];
	}
	cout << "Distance: " << sort(0, N - 1, b, temp) << endl;


	system("pause");
	return 0;
}

int sort(int lo, int hi, int* a, int* b) {
	if (hi <= lo) return 0;
	int count = 0;
	int mid = (lo + hi) / 2;
	count = count + sort(lo, mid, a, b);
	count = count + sort(mid + 1, hi, a, b);
	count = count + merge(lo, mid, hi, a, b);
	return count;
}

int merge(int lo, int mid, int hi, int* a, int* b) {
	int i = lo, j = mid + 1;
	int count = 0;
	for (int k = lo; k <= hi; k++) {
		if (i > mid) {
			b[k] = a[j];
			j++;
		}
		else {
			if (j > hi) {
				b[k] = a[i];
				i++;
			}
			else {
				if (a[j]<a[i]) {
					b[k] = a[j];
					count = count + mid - i + 1;
					j++;
				}
				else {
					b[k] = a[i];
					i++;
				}
			}
		}
	}
	for (int k = lo; k <= hi; k++) {
		a[k] = b[k];
	}
	return count;
}