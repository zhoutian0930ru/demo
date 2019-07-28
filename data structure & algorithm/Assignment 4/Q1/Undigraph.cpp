#include "Undigraph.h" 



Undigraph::Undigraph(int vertical)
{
	this->verticals = vertical;
	this->edges = 0;
	AdjacencyGraph = new list<int>[this->verticals];
	marked = new int[this->verticals];

}

int Undigraph::GetVerticals()
{
	return verticals;
}

int Undigraph::GetEdges()
{
	return edges;
}

void Undigraph::AddEdge(int verticalStart, int verticalEnd)
{
	AdjacencyGraph[verticalStart].push_back(verticalEnd);
	AdjacencyGraph[verticalEnd].push_back(verticalStart);
	this->edges++;
}

list<int>* Undigraph::GetAdjacencyGraph(int vetical)
{
	return &AdjacencyGraph[vetical];
}

bool Undigraph::acyclic()//BFS
{
	queue<int>*q = new queue<int>();
	int count = 0;
	bool acyclic = true;

	for (int i = 0; i < verticals; i++) {
		marked[i] = false;
	}

	q->push(0);
	marked[0] = true;

	while (q->size() != 0) {
		int v = q->front();
		q->pop();
		count = 0;

		cout << "start loop v=" << v << endl;
		for (list<int>::const_iterator iter = GetAdjacencyGraph(v)->begin(); iter != GetAdjacencyGraph(v)->end(); iter++)
		{
			if (marked[*iter]) {
				count++;
				cout << "  count++" << endl;
			}
			else {
				marked[*iter] = true;
				q->push(*iter);
				cout << "  push" << *iter << endl;
			}
		}
		if (count >= 2) {
			acyclic = false;
		}
	}
	return acyclic;
}

void Undigraph::PrintGraph()
{
	printf("The structure is£º\n");
	for (int i = 0; i<this->verticals; i++)
	{
		printf("%d->", i);
		for (list<int>::iterator j = this->AdjacencyGraph[i].begin(); j != AdjacencyGraph[i].end(); j++)
		{
			printf("%d->", *j);
		}
		printf("\n");

	}
}