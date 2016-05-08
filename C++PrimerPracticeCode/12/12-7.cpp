#include <iostream>
#include <vector>
#include <memory>
#include <initializer_list>

using namespace std;

shared_ptr<vector<int>> factory()
{
	return make_shared<vector<int>>();
}

void init(shared_ptr<vector<int>>& p)
{
	auto il = { 1, 2, 3 };

	for (initializer_list<int>::const_iterator it = il.begin(); it != il.end(); it++)
		p->push_back(*it);
}

int main()
{
	shared_ptr<vector<int>> p = factory();

	init(p);

	for (auto &e : *p)
		cout << e << " ";

	return 0;
}