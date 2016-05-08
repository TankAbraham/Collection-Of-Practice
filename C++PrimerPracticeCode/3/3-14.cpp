#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	string word;
	vector<string> v;
	while (cin >> word)
		v.push_back(word);

	int a;
	vector<int> v2;
	while (cin >> a)
		v2.push_back(a);

	return 0;
}