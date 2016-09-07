#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <utility>
#include <functional>

using namespace std;

#define GRAPH_INFINITY 100

struct TableEntry {
	bool known = false;
	int distence = GRAPH_INFINITY;
	size_t path = 0;
};

class Graph {
public:
	Graph(const int);
	void addEdge(size_t, size_t, int);
	vector<TableEntry> dijkstra(const size_t) const;

private:
	vector<unordered_map<size_t, int>> adjList;
	unsigned int vertex = 0;
};

inline 
Graph::Graph(const int v) : vertex(v) {
	adjList.resize(vertex + 1);
}

inline void
Graph::addEdge(size_t src, size_t dest, int weight) {
	adjList[src][dest] = weight;
}

inline vector<TableEntry>
Graph::dijkstra(const size_t start) const {
	vector<TableEntry> table(vertex + 1);

	//initialization
	table[start].distence = 0;

	const auto cmp = [](const pair<size_t, int>&lhs, const pair<size_t, int>&rhs) {
		return lhs.second > rhs.second;
	};

	priority_queue<pair<size_t, int>, vector<pair<size_t, int>>, decltype(cmp)> q(cmp);

	q.push(make_pair(start, 0));

	while (!q.empty()) {
		pair<size_t, int> curNode = q.top();
		q.pop();

		if (table[curNode.first].known) {
			continue;
		}

		table[curNode.first].known = true;

		for (const auto e : adjList[curNode.first]) {
			if (table[curNode.first].distence + e.second < table[e.first].distence) {
				table[e.first].distence = table[curNode.first].distence + e.second;
				table[e.first].path = curNode.first;
			}
			
			q.push(make_pair(e.first, e.second));
		}
	}

	return table;
}

void printTable(vector<TableEntry> table) {
	for (size_t i = 1; i < table.size(); i++) {
		cout << i << " " << table[i].known << " " << table[i].distence << " " << table[i].path << endl;
	}
}

int main() {
	Graph g(7);

	g.addEdge(1, 2, 2);
	g.addEdge(1, 4, 1);
	g.addEdge(2, 4, 3);
	g.addEdge(2, 5, 10);
	g.addEdge(3, 1, 4);
	g.addEdge(3, 6, 5);
	g.addEdge(4, 3, 2);
	g.addEdge(4, 6, 8);
	g.addEdge(4, 7, 4);
	g.addEdge(5, 7, 6);
	g.addEdge(7, 6, 1);
	g.addEdge(4, 5, 2);

	printTable(g.dijkstra(1));

	return 0;
}