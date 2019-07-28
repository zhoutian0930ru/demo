#include "BST.h"
#include "Node.h"
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	BST T;
	int key;

	//read connect data
	ifstream data_in("data.txt", ios::in);
	int readNumb = 0;
	if (data_in.is_open()) {
		while (!data_in.eof()) {
			data_in >> key;
			Node *p = new Node(key);
			T.insert(p);
			//if(readNumb==300000 || readNumb == 600000|| readNumb == 900000)
			//cout << readNumb << endl;
			readNumb++;
		}
	}
	cout << "Total number of data is: " << readNumb << endl;
	cout << "Read and Insert end." << endl;
	cout << "The value of rank(7) is: " << T.rank(7) << endl;
	cout << "The value of select(7) is: " << T.select(7) << endl;

	system("pause");
	return 0;

}