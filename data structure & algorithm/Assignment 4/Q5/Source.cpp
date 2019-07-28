#include <stdio.h>
#include <queue>
#include <iostream>
#include <list>
#include <fstream>
using namespace std;
#include "digraph.h"

int main() {
	int NodeNum;
	int edgeNum;

	fstream data_in("NYC.txt", ios::in);

	if (data_in.is_open()) {

		data_in >> NodeNum;
		data_in >> edgeNum;
		int from, to;
		double cost;
		int n = 0;

		digraph *g = new digraph(NodeNum);

		while (!data_in.eof()) {
			data_in >> from >> to >> cost;
			g->AddEdge(from, to, cost);
			//cout << n << ":   " << from << to << cost << endl;
			n++;
		}

		cout << "end" << endl;
		g->BFS();
		g->DFS();
	}


	system("pause");
	return 0;
}