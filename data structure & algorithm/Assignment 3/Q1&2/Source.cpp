
#include<ctime>
#include<cstdlib>
#include<iostream>
using namespace std;


#include"Node.h"
#include"tree.h"

int main() {
	
	//T.leanLeft() could lean the 2-3 tree to the left
	//T.leanRight() could lean the 2-3 tree to the right
	tree T;
	int const N = 1000;
	int a[N];
	srand((unsigned)time(NULL));


	for (int i = 0; i < N; i++) {
		Node *p = new Node(rand());
		T.insert(p);
	}


	T.print();

	cout << "count: " << T.getCount() << endl
		<< "Number of element: " << T.getNumb() << endl
		<< T.getCount() / T.getNumb() << endl;

	system("pause");
	return 0;

}