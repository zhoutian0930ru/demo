#include <iostream>  
#include <vector>  
#include <algorithm>  
#include <fstream>  
#include<time.h>
using namespace std;

struct Edge
{
	int u; 
	int v; 
	double w; 
	friend bool operator<(const Edge& E1, const Edge& E2)
	{
		return E1.w < E2.w;
	}
};
 
void MakeSet(vector<int>& uset, int n)
{
	uset.assign(n, 0);
	for (int i = 0; i < n; i++)
		uset[i] = i;
}
 
int FindSet(vector<int>& uset, int u)
{
	int i = u;
	while (uset[i] != i) i = uset[i];
	return i;
}
void Kruskal(const vector<Edge>& edges, int n)
{
	vector<int> uset;
	vector<Edge> SpanTree;
	double Cost = 0;
	int e1, e2;
	MakeSet(uset, n);
	for (int i = 0; i < edges.size(); i++) 
	{
		e1 = FindSet(uset, edges[i].u);
		e2 = FindSet(uset, edges[i].v);
		if (e1 != e2) 
		{
			SpanTree.push_back(edges[i]);
			Cost += edges[i].w;
			uset[e1] = e2; 
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

	cout << "Kruskal's algorithm:" << endl << endl;
	
	int n, m;
	in >> n >> m;
	vector<Edge> edges;
	edges.assign(m, Edge());
	for (int i = 0; i < m; i++)
		in >> edges[i].u >> edges[i].v >> edges[i].w;
	
	start = clock();
	sort(edges.begin(), edges.end()); 	
	Kruskal(edges, n);
	finish = clock();
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "totaltime: " << totaltime << endl << endl;

	in.close();

	system("pause");
	return 0;
}