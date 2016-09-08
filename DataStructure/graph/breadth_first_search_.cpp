/*
 * 广度优先搜索 
 */
#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

#define INFINITY_DISTENCE 100

struct TableEntry {
	unsigned int distence = INFINITY_DISTENCE;
	size_t path = 0;
};

class Graph {
public:
	Graph(const unsigned int);
	void addEdge(size_t, size_t);
	vector<TableEntry> bfs(size_t) const;
private:
	vector<unordered_set<size_t>> vertexs;
	unsigned int vertexNum;
};

inline 
Graph::Graph(const unsigned vn) : vertexNum(vn) {
	vertexs.resize(vertexNum + 1);
}

inline void
Graph::addEdge(size_t src, size_t dest) {
	vertexs[src].insert(dest);
}

inline vector<TableEntry>
Graph::bfs(size_t start) const {
	if (start < 1 || start > vertexNum) {
		return vector<TableEntry>();
	}

	vector<TableEntry> table(vertexNum + 1);
	queue<size_t> q;

	//initialization
	table[start].distence = 0;
	q.push(start);

	while (!q.empty()) {
		size_t cur = q.front();
		q.pop();

		for (const auto next : vertexs[cur]) {
			if (table[next].distence == INFINITY_DISTENCE) {
				table[next].distence = table[cur].distence + 1;
				table[next].path = cur;

				q.push(next);
			}
		}
	}

	return table;
}

void printTable(const vector<TableEntry>& table) {
	for (vector<TableEntry>::size_type i = 1; i < table.size(); i++) {
		cout << i << " " << table[i].distence << " " << table[i].path << endl;
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

	printTable(g.bfs(3));

	return 0;
}