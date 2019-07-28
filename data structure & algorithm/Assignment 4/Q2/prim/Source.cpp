#include <iostream>  
#include <fstream>  
#include <vector>  
#include <list>  
#include <queue>  
#include<time.h>
using namespace std;
struct Node
{
	int v;
	double w;
	Node(int a, double b) :v(a), w(b) {}
};
struct Edge
{
	int u;
	int v;
	double w;
	Edge(int a, int b, double c) :u(a), v(b), w(c) {}
	friend bool operator<(const Edge& E1, const Edge& E2)
	{
		return E1.w>E2.w;
	}
};
int n, m;
vector<list<Node>> Adj;
priority_queue<Edge> Q;

int FindSet(vector<int>& uset, int v)
{
	int i = v;
	while (i != uset[i]) i = uset[i];
	return i;
}

void Prim()
{
	double Cost = 0;  
	vector<Edge> SpanTree; 
	vector<int> uset(n, 0); 
	Edge E(0, 0, 0.0);
	for (int i = 0; i < n; i++) uset[i] = i;  
	for (auto it = Adj[0].begin(); it != Adj[0].end(); it++)
		Q.push(Edge(0, it->v, it->w));  
	while (!Q.empty())
	{
		E = Q.top();
		Q.pop();
		if (0 != FindSet(uset, E.v))
		{
			Cost += E.w;
			SpanTree.push_back(E);
			uset[E.v] = E.u;
			for (auto it = Adj[E.v].begin(); it != Adj[E.v].end(); it++)
				if (0 != FindSet(uset, it->v)) Q.push(Edge(E.v, it->v, it->w));
		}
	}
	cout << "Result:\n";
	cout << "Cost: " << Cost << endl;
	
	/*
	cout << "Edges:\n";
	for (int j = 0; j < SpanTree.size(); j++)
		cout << SpanTree[j].u << " " << SpanTree[j].v << " " << SpanTree[j].w << endl;
	*/
	cout << endl;
}
int main()
{
	ifstream in("data.txt");
	clock_t start, finish;
	double totaltime;

	cout << "Prim's algorithm:" << endl << endl;

	int u, v;
	double w;
	in >> n >> m;
	Adj.assign(n, list<Node>());
	for (int i = 0; i < m; i++)
	{
		in >> u >> v >> w;
		Adj[u].push_back(Node(v, w));
		Adj[v].push_back(Node(u, w));
	}
	
	start = clock();
	Prim();
	finish = clock();
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "totaltime: " << totaltime << endl << endl;

	in.close();

	system("pause");
	return 0;
}