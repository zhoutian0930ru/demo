#ifndef Undigraph_H
#define Undigraph_H

#include <list> 
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class digraph
{
private:
	int verticals;
	int edges;
	list<int> *AdjacencyGraph;
	int *marked;
	double **arc;
public:
	digraph(int vertical);
	int GetVerticals();
	int GetEdges();
	void AddEdge(int verticalStart, int verticalEnd, double cost);
	list<int>* GetAdjacencyGraph(int vetical);
	bool acyclic();
	void DFS();
	void BFS();
	void PrintGraph();

};

#endif