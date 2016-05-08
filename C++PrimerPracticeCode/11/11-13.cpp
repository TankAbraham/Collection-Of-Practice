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
		// 方法一 make_pair(param1, param2)
		v.push_back(make_pair(s, i));
		
		// 方法二 {lhs, rhs}
		v.push_back({ s, i });

		// 方法三 pair<typename, typename>(param1, param2)
		v.push_back(pair<string, int>(s, i));
	}
		

	for (auto &e : v)
		cout << e.first << " " << e.second << endl;

	return 0;
}