#include <vector>
#include <map>
#include <string>
#include <iostream>


using namespace std;

int main() {
	map<string, vector<int>> m = { 
		{"Tank", {1, 2}},
		{"Gun", {3, 4}}};
	
	map<string, vector<int>>::iterator it = m.find("Gun");

	cout << it->first << " " << it->second[0] << " " << it->second[1] ;


	return 0;
}