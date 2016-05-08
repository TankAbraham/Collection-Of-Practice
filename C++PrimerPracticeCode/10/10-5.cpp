#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	char c1[] = "abc";
	char c2[] = "def";
	char c3[] = "ghi";
	vector<char*> roster1 = { c1, c2, c3 };
	vector<char*> roster2 = { c1, c3, c2 };
	vector<char*> roster3(roster1);
	cout << equal(roster1.begin(), roster1.end(), roster2.begin()) << endl;
	cout << equal(roster1.begin(), roster1.end(), roster3.begin()) << endl;
	return 0;
}