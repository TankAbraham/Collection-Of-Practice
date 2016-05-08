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
		// fam is pair#include <iostream>
#include <vector>
#include <map>
#include <string>


using namespace std;

int main() {
	auto pa1 = new string("a1");
	auto pa2 = new string("a2");
	auto pb1 = new string("b1");
	auto pc1 = new string("c1");
	auto pc2 = new string("c2");
	auto pc3 = new string("c3");

	auto p1 = new vector<string*>{ pa1, pa2 };
	auto p2 = new vector<string*>{ pb1 };
	auto p3 = new vector<string*>{ pc1, pc2, pc3 };

	map<string, vector<string*>* > families{
		{"a", p1},
		{"b", p2},
		{"c", p3}
	};

	for (auto &fam : families) {
		// fam is pair
		cout << fam.first << endl;
		for (unsigned i = 0; i < fam.second->size(); i++) {
			// fam.second is *vecotr<string*>
			cout << *((*(fam.second))[i]) << " ";
		}
		cout << endl;
	}


	delete pa1;
	delete pa2;
	delete pb1;
	delete pc1;
	delete pc2;
	delete pc3;

	delete p1;
	delete p2;
	delete p3;

	return 0;
}