#include <map>
#include <utility>
#include <string>
#include <iostream>


using namespace std;

int main() {
	map<int, string> m;
	m.insert({ 1, "A" });

	map<int, string>::iterator it = m.begin();
	it->second = "B";

	cout << it->first << " " << it->second << endl;

	return 0;
}