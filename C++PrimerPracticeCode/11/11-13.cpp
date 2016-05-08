#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <vector>


using namespace std;

int main() {
	ifstream fin("data11.dat");
	vector<pair<string, int>> v;

	string s;
	int i;

	while (fin >> s >> i) {
		// ����һ make_pair(param1, param2)
		v.push_back(make_pair(s, i));
		
		// ������ {lhs, rhs}
		v.push_back({ s, i });

		// ������ pair<typename, typename>(param1, param2)
		v.push_back(pair<string, int>(s, i));
	}
		

	for (auto &e : v)
		cout << e.first << " " << e.second << endl;

	return 0;
}