#ifndef Undigraph_H
#define Undigraph_H

#include <list> 
#include <iostream>
#include <queue>
using namespace std;

class Undigraph
{
private:
	int verticals;
	int edges;
	list<int> *AdjacencyGraph;
	int *marked;
public:
	Undigraph(int vertical);
	int GetVerticals();
	int GetEdges();
	void AddEdge(int verticalStart, int verticalEnd);
	list<int>* GetAdjacencyGraph(int vetical);	
	bool acyclic();
	void PrintGraph();

};

#endif