#include<iostream>
#include<algorithm>
#include<vector>
#include<fstream>
#include<time.h>
using namespace std;


int main(){
	int const N = 1024;
	int const max = 8192;
	int data_1[N];
	int data_2[N];
	int qfMap[max];//quick find map
	int quMap[max];//quick union map
	int wbMap[max];//quick union with weight balancing
	int weight[max];
	int count = 0;

	clock_t start, finish;
	double totaltime;

	//read connect data
	ifstream data_in("1024pair.txt", ios::in);

	if (data_in.is_open()) {
		while (!data_in.eof()) {
			data_in >> data_1[count] >> data_2[count];
			//cout << "yes" << endl;
			count++;
		}
	}

	//initialize
	for (int i = 0; i < max; i++) {
		qfMap[i] = i;
		quMap[i] = i;
		wbMap[i] = i;
		weight[i] = 1;
	}

	cout << "the data has size: " << N << endl;

	//Quick find UNION
	start = clock();
	for (int j = 0; j < N; j++) {
		int sample;
		int target;
		if (data_1[j] > data_2[j]) {
			sample = data_2[j];
			target = data_1[j];
		}
		else {
			sample = data_1[j];
			target = data_2[j];
		}
		
		for (int k = 0; k < max; k++) {
			if (qfMap[k] == sample)
				qfMap[k] = target;
		}
	}
	finish = clock();
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "totaltime for quick find UNION: " << totaltime << endl;

	//Quick find Find
	start = clock();
	for (int i = 0; i < max; i++) {
		for (int j = i + 1; j < max; j++) {
			if (qfMap[i] == qfMap[j]);
		}
	}
	finish = clock();
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "totaltime for quick find FIND: " << totaltime << endl;

	//Quick union UNION
	start = clock();
	for (int i = 0; i < N; i++) {
		if (data_1[i] > data_2[i]) {
			quMap[data_2[i]] = quMap[data_1[i]];
		}
		else {
			quMap[data_1[i]] = quMap[data_2[i]];
		}
	}
	finish = clock();
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "totaltime for quick union UNION: " << totaltime << endl;

	//Quick union FIND
	int root1, root2;
	start = clock();
	for (int i = 0; i < max; i++) {
		for (int j = i + 1; j < max; j++) {
			root1 = i;
			root2 = j;
			while (root1 != quMap[root1]) {
				root1 = quMap[root1];
			}
			while (root2 != quMap[root2]) {
				root2 = quMap[root2];
			}
			if (root1 == root2);
		}
	}
	finish = clock();
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "totaltime for quick union FIND: " << totaltime << endl;

	//Quick union with weight balance UNION
	start = clock();
	for (int i = 0; i < N; i++) {
		if (weight[data_1[i]] > weight[data_2[i]]) {
			wbMap[data_2[i]] = wbMap[data_1[i]];
			weight[data_1[i]] += weight[data_2[i]];
		}
		else {
			wbMap[data_1[i]] = wbMap[data_2[i]];
			weight[data_2[i]] += weight[data_1[i]];
		}
	}
	finish = clock();
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "totaltime for quick union with weight balance UNION: " << totaltime << endl;

	//Quick union with weight balance FIND
	start = clock();
	for (int i = 0; i < max; i++) {
		for (int j = i + 1; j < max; j++) {
			root1 = i;
			root2 = j;
			while (root1 != quMap[root1]) {
				root1 = quMap[root1];
			}
			while (root2 != quMap[root2]) {
				root2 = quMap[root2];
			}
			if (root1 == root2);
		}
	}
	finish = clock();
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "totaltime for quick union with weight balance FIND: " << totaltime << endl;



	system("pause");
	return 0;
}


