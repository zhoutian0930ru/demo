#include"Graph_DG.h"


bool check(int Vexnum, int edge) {
	if (Vexnum <= 0 || edge <= 0 || ((Vexnum*(Vexnum - 1)) / 2) < edge)
		return false;
	return true;
}
int main() {
	int vexnum; int edge;

	ifstream in("data_b.txt");
	in >> vexnum >> edge;
	in.close();

	Graph_DG graph(vexnum, edge);
	graph.createGraph();
	graph.print();
	graph.Dijkstra(4);
	graph.print_path(4);
	system("pause");

	return 0;
}