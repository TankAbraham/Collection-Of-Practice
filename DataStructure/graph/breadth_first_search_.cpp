/*
 * 广度优先搜索 
 */
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <utility>

using namespace std;

class Graph
{
public:
	Graph(int);
	void addEdge(size_t, size_t);
	void bfs(size_t);
private:
	vector<pair<int, list<size_t>>> adjList;
	int vertexNum;
};

inline
Graph::Graph(int vertexNum) : vertexNum(vertexNum)
{
	//let index 0 always empty
	for (int i = 0; i <= vertexNum; i++)
	{
		adjList.push_back(make_pair(INT_MAX, list<size_t>()));
	}
};

inline void
Graph::addEdge(size_t src, size_t dest)
{
	adjList[src].second.push_back(dest);
}

inline void
Graph::bfs(size_t start)
{
	queue<size_t> q;
	q.push(start);
	adjList[start].first = 0;

	while (!q.empty())
	{
		size_t i = q.front();
		q.pop();

		for (const auto next : adjList[i].second)
		{
			if (adjList[next].first == INT_MAX)
			{
				adjList[next].first = adjList[i].first + 1;
				q.push(next);
			}
		}
	}
}

int main() {
	Graph g(7);

	g.addEdge(1, 2);
	g.addEdge(1, 4);
	g.addEdge(2, 4);
	g.addEdge(2, 5);
	g.addEdge(3, 1);
	g.addEdge(3, 6);
	g.addEdge(4, 3);
	g.addEdge(4, 5);
	g.addEdge(4, 6);
	g.addEdge(4, 7);
	g.addEdge(5, 7);
	g.addEdge(7, 6);

	g.bfs(3);

	return 0;
}