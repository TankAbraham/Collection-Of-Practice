#include <map>
#include <string>
#include <vector>
#include <utility>
#include <iostream>


using namespace std;

int main() {
	map<string, vector<int>> m;

	pair<map<string, vector<int>>::iterator, bool> par = m.insert({ "first", {10} });

	cout << par.first->first << " " << par.first->second[0] << " " << par.second ;
	
	
	return 0;
}