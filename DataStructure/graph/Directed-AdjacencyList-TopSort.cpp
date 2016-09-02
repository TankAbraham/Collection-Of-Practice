/*
 * 拓扑排序 - 顶点名哈希存储 - 有向图 - 邻接表
 */ 
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <unordered_map>
#include <queue>

using namespace std;

class GraphAdjacencyList
{
public:
	GraphAdjacencyList(const int);
	void addEdge(const string&, const string&);
	void printGraph() const;
	void topSort() const;

private:
	int vertex;
	vector<list<size_t>> adjList;
	unordered_map<string, size_t> nameIndexMap;
	vector<string> indexNameMap;

	size_t getIndexByName(const string&);
	string getNameByIndex(const size_t) const;
};

inline
GraphAdjacencyList::GraphAdjacencyList(const int v) : vertex(v)
{
	adjList.resize(vertex);
	indexNameMap.resize(vertex);
}

inline size_t
GraphAdjacencyList::getIndexByName(const string &name)
{
	size_t index;
	unordered_map<string, size_t>::iterator it = nameIndexMap.find(name);

	if (it == nameIndexMap.end())
	{
		//first time name apperance
		index = nameIndexMap.size();

		nameIndexMap[name] = index;
		indexNameMap[index] = name;
	}
	else
	{
		index = it->second;
	}

	return index;
}

inline string
GraphAdjacencyList::getNameByIndex(const size_t index) const
{
	return indexNameMap.at(index);
}

inline void
GraphAdjacencyList::addEdge(const string &src, const string &dest)
{
	size_t srcIndex = getIndexByName(src);
	size_t destIndex = getIndexByName(dest);

	adjList[srcIndex].push_back(destIndex);
}

inline void
GraphAdjacencyList::printGraph() const 
{
	for (int row = 0; row < vertex; row++)
	{
		cout << getNameByIndex(row) << endl;

		for (auto e : adjList[row])
		{
			cout << getNameByIndex(e) << " ";
		}

		cout << endl;
	}
}

inline void
GraphAdjacencyList::topSort() const
{
	unordered_map<size_t, int> indegree;
	queue<size_t> zeroIndegreeVertex;

	//set every vertex indegree
	for (int row = 0; row < vertex; row++)
	{
		if (indegree.find(row) == indegree.end())
		{
			indegree[row] = 0;
		}

		for (auto e : adjList[row])
		{
			indegree[e]++;
		}
	}

	//enqueue 0 indegree vertex
	for (auto e : indegree) {
		if (e.second == 0)
		{
			zeroIndegreeVertex.push(e.first);
		}
	}

	//print top
	int count = 0;
	while (!zeroIndegreeVertex.empty())
	{
		size_t index = zeroIndegreeVertex.front(); 
		zeroIndegreeVertex.pop();

		cout << getNameByIndex(index) << " ";

		for (auto e : adjList[index])
		{
			indegree[e]--;

			if (indegree[e] == 0)
			{
				zeroIndegreeVertex.push(e);
			}
		}

		count++;
	}

	if (count != vertex)
	{
		cout << "graph has a cycle" << endl;
	}
}


int main() {
	GraphAdjacencyList g(7);

	g.addEdge("1", "2");
	g.addEdge("1", "4");
	g.addEdge("1", "3");
	g.addEdge("2", "4");
	g.addEdge("2", "5");
	g.addEdge("3", "6");
	g.addEdge("4", "6");
	g.addEdge("4", "7");
	g.addEdge("4", "3");
	g.addEdge("5", "4");
	g.addEdge("5", "7"); 
	g.addEdge("7", "6");

	//g.printGraph();

	g.topSort();

	return 0;
}