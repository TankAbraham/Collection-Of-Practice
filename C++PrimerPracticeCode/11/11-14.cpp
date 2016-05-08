#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>


using namespace std;

int main() {
	ifstream fin("data12.dat");

	vector<pair<string, string>> children;

	string name, birthay;
	while (fin >> name >> birthay){
		children.push_back({ name, birthay });
	}


	for (auto &e : children)
		cout << e.first << " " << e.second << endl;

	return 0;
}