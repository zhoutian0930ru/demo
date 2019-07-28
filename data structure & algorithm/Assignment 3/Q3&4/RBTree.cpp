/**
* C++ Red-Black Tree
*
*/

#include <windows.h>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include "RBTree.h"
using namespace std;

int main()
{
	/*
	select Test 3 or 4;
	select N;
	output;
	*/
	
	
	int const Test = 3;
	     //0 for Q3 given dataset
	     //3 for Q3
	     //4 for Q4      
	int const N = 100000;        //size of data
	int check_insert = 0;    // "Insert"operation test(0£¬close£»1£¬open)
	double a3[100];
	double a4[1000];

	if (Test == 0) {
		//read connect data
		ifstream data_in("data.txt", ios::in);
		int readNumb = 0;
		int t;
		RBTree<int>* tree = new RBTree<int>();
		if (data_in.is_open()) {
			while (!data_in.eof()) {
				data_in >> t;
				tree->insert(t);
				// check insert if neccessary
				if (check_insert)
				{
					cout << "Node: " << t << endl;
					cout << "Tree: " << endl;
					tree->print();
					cout << endl;
				}
				readNumb++;
			}
		}
		cout << "Red Count: " << tree->searchRed() << endl
			<< "Size of data set is: " << readNumb << endl;
		cout << "The percentage of red nodes for given data set is: "
			<< tree->searchRed() / (double)readNumb << endl;
		tree->destroy();
	}
	
	if (Test == 3) {			
		
		//100 trials for Q3
		for (int i = 0; i < 100; i++) {
			RBTree<int>* tree = new RBTree<int>();
			srand((unsigned)time(NULL));
			for (int i = 0; i < N; i++) {
				int t = rand();
				tree->insert(t);
				// check insert if neccessary
				if (check_insert)
				{
					cout << "Node: " << t << endl;
					cout << "Tree: " << endl;
					tree->print();
					cout << endl;
				}
			}
			cout << "Red Count: " << tree->searchRed() << "   " << i << endl;
			//cout << "The percentage of red nodes for N=" << N << " data set is: "
			//<< tree->searchRed() / (double)N << endl;

			a3[i] = tree->searchRed();

			//destroy the tree
			tree->destroy();
			Sleep(1000);
		}

		ofstream outf;
		outf.open("output_3.txt");
		if (outf.is_open()) {
			for (int i = 0; i < 100; i++) {
				outf << a3[i] << endl;
			}
		}
	}//end if

	if (Test == 4) {
		//1000 trials for Q4
		for (int i = 0; i < 1000; i++) {
			RBTree<int>* tree = new RBTree<int>();
			srand((unsigned)time(NULL));
			for (int i = 0; i < N; i++) {
				int t = rand();
				tree->insert(t);
				// check insert if neccessary
				if (check_insert)
				{
					cout << "Node: " << t << endl;
					cout << "Tree: " << endl;
					tree->print();
					cout << endl;
				}
			}
	
			cout << "Average path length: " << tree->getCount() / (double)N
				<< "  " << i << endl;
			a4[i] = tree->getCount();

			//destroy the tree
			tree->destroy();
			Sleep(1000);
		}

		ofstream outf;
		outf.open("output_4.txt");
		if (outf.is_open()) {
			for (int i = 0; i < 1000; i++) {
				outf << a4[i] << endl;
			}
		}
		
	}
	

	system("pause");
	return 0;
}