/*
 * 无向图 - 邻接矩阵
 */
#include <iostream>
#include <vector>

using namespace std;

class GraphAdjacencyMatrix {
public:
	GraphAdjacencyMatrix(int);
	void addEdge(int, int);
	void printGraph() const;
private:
	int vertex;
	vector<vector<int>> matrix;
};

inline 
GraphAdjacencyMatrix::GraphAdjacencyMatrix(const int v) : vertex(v) 
{
	matrix.resize(v);
	for (auto &e : matrix) {
		e.resize(v);
	}
}

inline void
GraphAdjacencyMatrix::addEdge(const int src, const int dest) {
	if (src >= vertex || dest >= vertex)
	{
		cout << "wrong input src = " << src << " dest = " << dest << endl;
		return ;
	}

	matrix[src][dest] = 1;
	matrix[dest][src] = 1;
}

inline void
GraphAdjacencyMatrix::printGraph() const {
	for (int row = 0; row < vertex; row++)
	{
		cout << row << endl;

		for (int col = 0; col < vertex; col++)
		{
			if (matrix[row][col] == 1)
			{
				cout << col << " ";
			}
		}

		cout << endl;
	}
}

int main() {
	GraphAdjacencyMatrix g(5);

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