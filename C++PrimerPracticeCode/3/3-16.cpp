#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	vector<string> v6{ 10 };
	cout << v6[0] << endl;

	vector<string> v7{ 10, "hi" };
	cout << v7[0] << v7[1] << endl;

	return 0;
}