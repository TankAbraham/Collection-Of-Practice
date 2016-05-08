#include <vector>
#include <iostream>

using namespace std;

int main(){
	vector<int > v{1, 2, 3};
	auto elem1 = v.begin();
	auto elem2 = v.begin();
	v.erase(elem1, elem2);
	for (auto e : v) cout << e << " ";
	cout << endl;

	auto elem3 = v.end();
	v.erase(elem1, elem3);
	for (auto e : v) cout << e << " ";
	cout << endl;

	vector<int> v2{ 1, 2, 3 };
	auto elem4 = v2.end();
	auto elem5 = v2.end();
	v2.erase(elem4, elem5);
	for (auto e : v2) cout << e << " ";
	cout << endl;

	return 0;
}