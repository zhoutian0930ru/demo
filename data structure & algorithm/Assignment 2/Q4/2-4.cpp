
#include<iostream>
#include<fstream>
using namespace std;
int sort(int, int, int*, int*);
int merge(int, int, int, int*, int*);

int main(){
	int const N = 2048;
	int p = 3;
	int a[N];
	int b[N];
	int read[N];
	int Number;


	//read connect data
	ifstream data_in("data0.2048", ios::in);
	int readNumb=0;
	if (data_in.is_open()) {
		while (!data_in.eof()) {
			data_in >> read[readNumb];
			readNumb++;
		}
	}

	for (int i = 0; i < N; i++) {
		a[i] = read[i];
		b[i] = read[i];
	}


	//mergesort.recursive
	Number = sort(0, N - 1, a, b);
	cout << "Number of comparisons (merge sort_recursive): " << Number << endl;


	for (int i = 0; i < N; i++) {
		a[i] = read[i];
		b[i] = read[i];
	}

	//nergesirt.bottom-up
	Number = 0;
	for (int size = 2; (size/2) < N; size = 2 * size) {
		int point = 0;
		while ((point+1)*size <= N) {
			Number = Number + merge(point*size, point*size + (size - 1) / 2, point*size + size - 1, a, a);
			point++;
		}
		if (point*size < N - 1) {
			Number = Number + merge(point*size, point*size + (size - 1) / 2, N - 1, a, b);
		}
	}
	cout << "Number of comparisons (merge sort_bottom-up): " << Number << endl;


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

int merge(int lo, int mid, int hi, int* a,int* b) {
	int i = lo, j = mid + 1;
	int count = 0;
	for (int k = lo; k <= hi; k++) {
		if (i > mid) {
			b[k] = a[j];
			j++;
		}
		else{
			if (j > hi) {
				b[k] = a[i];
				i++;
			}
			else {
				if(a[j]<a[i]){
					b[k] = a[j];
					j++;
				}
				else {
					b[k] = a[i];
					i++;
				}
			}
		}
		count++;
	}
	for (int k = lo; k <= hi; k++) {
		a[k] = b[k];
	}
	return count;
}