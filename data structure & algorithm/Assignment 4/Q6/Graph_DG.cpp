#include"Graph_DG.h"

Graph_DG::Graph_DG(int vexnum, int edge) {
	this->vexnum = vexnum;
	this->edge = edge;
	arc = new double*[this->vexnum];
	dis = new Dis[this->vexnum];
	for (int i = 0; i < this->vexnum; i++) {
		arc[i] = new double[this->vexnum];
		for (int k = 0; k < this->vexnum; k++) {
			arc[i][k] = INT_MAX;
		}
	}
}

Graph_DG::~Graph_DG() {
	delete[] dis;
	for (int i = 0; i < this->vexnum; i++) {
		delete this->arc[i];
	}
	delete arc;
}

bool Graph_DG::check_edge_value(int start, int end, double weight) {
	if (start<0 || end<0 || start>vexnum || end>vexnum || weight < 0) {
		return false;
	}
	return true;
}

void Graph_DG::createGraph() {
	
	ifstream in("data_b.txt");
	int start;
	int end;
	double weight;
	int n, m;
	in >> n >> m;
	for (int i = 0; i < m; i++) {
		in >> start >> end >> weight;
		arc[start][end] = weight;
	}
		
	in.close();
	
}

void Graph_DG::print() {
	cout << "Adjacent Matrix£º" << endl;
	int count_row = 0; 
	int count_col = 0; 
	while (count_row != this->vexnum) {
		count_col = 0;
		while (count_col != this->vexnum) {
			if (arc[count_row][count_col] == INT_MAX)
				cout << "¡Þ" << " ";
			else
				cout << arc[count_row][count_col] << " ";
			++count_col;
		}
		cout << endl;
		++count_row;
	}
}

void Graph_DG::Dijkstra(int begin) {
	int i;
	for (i = 0; i < this->vexnum; i++) {
		dis[i].path =to_string(begin) + "-->" + to_string(i);
		dis[i].value = arc[begin][i];
	}
	dis[begin].value = 0;
	dis[begin].visit = true;

	int count = 1;
	while (count != this->vexnum) {
		int temp = 0;
		double min = INT_MAX;
		for (i = 0; i < this->vexnum; i++) {
			if (!dis[i].visit && dis[i].value<min) {
				min = dis[i].value;
				temp = i;
			}
		}
		dis[temp].visit = true;
		++count;
		for (i = 0; i < this->vexnum; i++) {
			if (!dis[i].visit && arc[temp][i] != INT_MAX && (dis[temp].value + arc[temp][i]) < dis[i].value) {
				
				dis[i].value = dis[temp].value + arc[temp][i];
				dis[i].path = dis[temp].path + "-->" + to_string(i);
			}
		}
	}

}

void Graph_DG::print_path(int begin) {
	//string str;
	//str = "v" + to_string(begin);
	cout << "The shortest path from source=" << begin << " is:" << endl;
	for (int i = 0; i != this->vexnum; i++) {
		if (dis[i].value != INT_MAX)
			cout << dis[i].path << "=" << dis[i].value << endl;
		else {
			cout << dis[i].path << "has no shortest path" << endl;
		}
	}
}