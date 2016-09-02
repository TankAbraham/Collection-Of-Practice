/*
 * 邻接表 - 无向图
 */
#include <iostream>
#include <vector>
#include <list>

using namespace std;

class GraphAdjacencyList
{
public:
	GraphAdjacencyList(const int);
	void addEdge(const int,const int);
	void printGraph() const;
private:
	vector<list<int>> adjList;
	int vertex;
};

inline
GraphAdjacencyList::GraphAdjacencyList(const int v) : vertex(v) 
{
	adjList.resize(vertex);
}

inline void
GraphAdjacencyList::addEdge(const int src, const int dest) 
{
	if (src >= vertex || dest >= vertex)
	{
		cout << "wrong input src = " << src << " dest = " << dest << endl;
		return;
	}

	adjList[src].push_back(dest);
	adjList[dest].push_back(src);
}

inline void
GraphAdjacencyList::printGraph() const
{
	for (int row = 0; row < vertex; row++)
	{
		cout << row << endl;

		for (auto e : adjList[row])
		{
			cout << e << " ";
		}

		cout << endl;
	}
}

int main() {
	GraphAdjacencyList g(5);

	g.addEdge(0, 1);
	g.addEdge(0, 4);
	g.addEdge(1, 2);
	g.addEdge(1, 3);
	g.addEdge(1, 4);
	g.addEdge(2, 3);
	g.addEdge(3, 4);

	g.printGraph();

	return 0;
}