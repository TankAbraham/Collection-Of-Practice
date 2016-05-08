#include <iostream>
#include <vector>
#include <map>
#include <string>


using namespace std;

int main() {
	auto p1 = new vector<string>{ "a1", "a2", "a3" };
	auto p2 = new vector<string>{ "b1", "b2", "b3", "b4" };
	auto p3 = new vector<string>{ "c1", "c2" };

	map<string, vector<string>* > families{
		{"a", p1},
		{"b", p2},
		{"c", p3}
	};

	for (auto &fam : families) {
		// fam is pair
		cout << fam.first << endl;
		for (unsigned i = 0; i < fam.second->size(); i++)
			cout << (*(fam.second))[i] << " ";
		cout << endl;
	}



	delete p1;
	delete p2;
	delete p3;

	return 0;
}