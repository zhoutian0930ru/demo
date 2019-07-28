#include <stdio.h>
#include <queue>
#include <iostream>
#include <list>
#include <fstream>
using namespace std;
#include "Undigraph.h"

int main() {
	int NodeNum;
	int edgeNum;
	
	fstream data_in("data.txt", ios::in);

	if (data_in.is_open()) {

		data_in >> NodeNum;
		data_in >> edgeNum;
		int from, to;
		double cost;
		int n = 0;

		Undigraph *g = new Undigraph(NodeNum);

		while (!data_in.eof()) {
			data_in >> from >> to >> cost;
			g->AddEdge(from, to);
			cout << n << ":   " << from << to << cost << endl;
			n++;
		}

		if (g->acyclic() == 0)
			cout << "The given graph is not an acyclic graph." << endl;
		else {
			cout << "The given graph is an acyclic graph." << endl;
		}
	}
	
	
	system("pause");
	return 0;
}