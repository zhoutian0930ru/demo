#include<iostream>
#include<algorithm>
#include<vector>
#include<fstream>
#include<time.h>
using namespace std;

int main(){
	int count = 0;
	int const N = 32;
	int a[N] = { 0 };

	clock_t start, finish;
	double totaltime;
	
	//read the data from txt and store it to vector
	ifstream data_in("32int.txt", ios::in);

	if (data_in.is_open()) {
		while (!data_in.eof()) {
			data_in >> a[count];
			//cout << "yes" << endl;
			count++;
		}
	}
	vector<int> v(a, a + N);

	//sort
	sort(v.begin(), v.end());

	
	//naive 3_sum
	count = 0;
	start = clock();
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			for (int k = j + 1; k < N; k++) {
				if (v[i] + v[j] + v[k] == 0)
					count++;
			}
		}
	}
	finish = clock();
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "totaltime: " << totaltime << endl;

	
	
	//sophisticated 3_sum
	count = 0;
	int temp;
	start = clock();
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			count += binary_search(v.begin()+j+1, v.end(), -v[i] - v[j]);
		}
	}
	finish = clock();
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "totaltime: " << totaltime << endl;

	
	
	system("pause");
	return 0;
}
