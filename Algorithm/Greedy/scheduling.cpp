/*
 * 《数据结构、算法与应用——C++语言描述》 17-5 机器调度
 */
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Task {
	Task(char id, int start, int finish) :id(id), s(start), f(finish) {}
	char id;
	int s;
	int f;
};

struct Machine {
	Machine(size_t id) : id(id), u(0), v() {}
	Machine() {}
	size_t id;
	int u;
	vector<char> v;
};

vector<Machine> schedule(vector<Task>& tasks) {
	sort(tasks.begin(), tasks.end(), 
		[](const Task& lhs, const Task& rhs) {
		return lhs.s < rhs.s;
	});

	auto machineCmp = [](const Machine& lhs, const Machine& rhs) {return lhs.u > rhs.u; };

	priority_queue<Machine, vector<Machine>, decltype(machineCmp)> machines(machineCmp);

	for (auto e : tasks) {
		Machine m;

		if (!machines.empty() && e.s >= machines.top().u) {
			m = machines.top();
			machines.pop();
		}
		else {
			m.id = machines.size() + 1;
		}

		m.u = e.f;
		m.v.push_back(e.id);
		machines.push(m);
	}

	vector<Machine> v;
	while (!machines.empty()){
		v.push_back(machines.top());
		machines.pop();
	}

	return v;
}

int main() {
	vector<Task> v = {
		{ 'a', 0, 2},
		{ 'b', 3, 7 },
		{ 'c', 4, 7 },
		{ 'd', 9, 11 },
		{ 'e', 7, 10 },
		{ 'f', 1, 5 },
		{ 'g', 6, 8 }
	};

	vector<Machine> scheduling = schedule(v);
	
	for (auto machine : scheduling) {
		cout << machine.id << endl;
		for (auto e : machine.v) {
			cout << e << " ";
		}
		cout << endl;
	}

	return 0;
}