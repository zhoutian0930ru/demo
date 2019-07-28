#include "digraph.h" 



digraph::digraph(int vertical)
{
	this->verticals = vertical;
	this->edges = 0;
	AdjacencyGraph = new list<int>[this->verticals];
	marked = new int[this->verticals];
	arc = new double*[this->verticals];
	for (int i = 0; i < this->verticals; i++) {
		arc[i] = new double[this->verticals];
		for (int k = 0; k < this->verticals; k++) {
			arc[i][k] = INT_MAX;
		}
	}

}

int digraph::GetVerticals()
{
	return verticals;
}

int digraph::GetEdges()
{
	return edges;
}

void digraph::AddEdge(int verticalStart, int verticalEnd,double cost)
{
	AdjacencyGraph[verticalStart].push_back(verticalEnd);
	this->edges++;
	arc[verticalStart][verticalEnd] = cost;
}

list<int>* digraph::GetAdjacencyGraph(int vetical)
{
	return &AdjacencyGraph[vetical];
}

bool digraph::acyclic()//BFS
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

void digraph::DFS()
{
	stack<int>*q = new stack<int>();
	int count = 0;
	bool acyclic = true;

	for (int i = 0; i < verticals; i++) {
		marked[i] = false;
	}

	q->push(0);
	marked[0] = true;


	while (q->size() != 0) {
		int v = q->top();
		q->pop();

		//cout << "start loop v=" << v << endl;
		for (list<int>::const_iterator iter = GetAdjacencyGraph(v)->begin(); iter != GetAdjacencyGraph(v)->end(); iter++)
		{
			if (!marked[*iter]) {
				marked[*iter] = true;
				count++;
				q->push(*iter);
				//cout << "  push" << *iter << " " << count << endl;	
			}
		}
	}
}

void digraph::BFS()
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

		//cout << "start loop v=" << v << endl;
		for (list<int>::const_iterator iter = GetAdjacencyGraph(v)->begin(); iter != GetAdjacencyGraph(v)->end(); iter++)
		{
			if (!marked[*iter]) {
				marked[*iter] = true;
				count++;
				q->push(*iter);				
				//cout << "  push" << *iter << " " << count << endl;	
			}
		}
	}
}

void digraph::PrintGraph()
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