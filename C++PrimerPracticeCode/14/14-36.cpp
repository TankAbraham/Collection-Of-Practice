#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iterator>

using namespace std;

struct StrVector {
	void operator() (istream& is, vector<string>& v) {
		string s;
		if (getline(is, s))
			*back_inserter(v) = s;
	}
};

int main() {
	ifstream fin("data7.dat");
	vector<string> v;

	for (int i = 0; i < 4; i++) {
		auto callable = StrVector();
		callable(fin, v);
	}
	
	for (auto &e : v)
		cout << e << endl;

	return 0;
}
