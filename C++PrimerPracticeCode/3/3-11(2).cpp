#include <iostream>
#include <string>

using namespace std;

int main()
{
	const string s = "keep out!";
	for(auto &c : s)
		cout << c << " ";

	return 0;
}