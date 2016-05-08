#include <iostream>
#include <vector>
#include <map>
#include <string>


using namespace std;

int main() {
	map<string, vector<string* >* > families;

	string s;

	for (unsigned i = 0; i < 3; i++) {
		cout << "please input familiy name" << endl;
		cin >> s;
		families[s] = new vector<string* >;
		for (unsigned j = 0; j < 3; j++) {
			cout << "please input first name" << endl;
			cin >> s;
			auto p = new string(s);
			families[s]->push_back(p);
		}
	}

	for (auto &fam : families) {
		// fam is pair
		cout << fam.first << endl;
		for (unsigned i = 0; i < fam.second->size(); i++) {
			// fam.second is *vecotr<string*>
			cout << *((*(fam.second))[i]) << " ";
		}
		cout << endl;
	}

	return 0;
}