#include<iostream>
#include<algorithm>
#include<vector>
#include<fstream>
#include<time.h>
using namespace std;

int main() {
	int const N=4096;
	double a[N] = { 0 };
	int count = 0;
	int begin, end;

	clock_t start, finish;
	double totaltime;

	cout << "Size of data: " << N << endl;
	
	//read the data from txt and store it to vector
	ifstream data_in("4096int.txt", ios::in);
	if (data_in.is_open()) {
		while (!data_in.eof()) {
			data_in >> a[count];
			//cout << "yes" << endl;
			count++;
		}
	}
	vector<double> v(a, a + N);

	//sort ascending
	sort(v.begin(), v.end());

	//linear algorithm to count the number of pairs that sum to zero
	count = 0;
	start = clock();
	for (int i = 0; i < N; i++) {
		begin = 0, end = N - 1;
		if (v[begin] + v[end] < 0) {
			begin++;
		}
		if (v[begin] + v[end] > 0) {
			end--;
		}
		if (v[begin] + v[end] == 0) {
			begin++;
			end--;
			count++;
		}
	}
	finish = clock();
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "Totaltime for pair sum(linear algorithm): " << totaltime << endl;

	//quadratic algorithm to count the number of pairs that sum to zero
	count = 0;
	start = clock();
	for (int i=0; i < N; i++) {
		begin = i;
		end = N - 1;
		for (int j = i + 1; j < N; j++) {
			if (v[begin] + v[end] < -v[i]) {
				begin++;
			}
			if (v[begin] + v[end] > -v[i]) {
				end--;
			}
			if (v[begin] + v[end] == -v[i]) {
				begin++;
				end--;
				count++;
			}
		}	
	}
	finish = clock();
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "Totaltime for 3_sum(quadratic algorithm): " << totaltime << endl;


	system("pause");
	return 0;

}
