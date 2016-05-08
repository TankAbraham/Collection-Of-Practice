#include <iostream>
#include <string>

using namespace std;

int main()
{
	const string s = "Hello word";
	for (auto &c : s)
		cout << c << endl;
	
	return 0;
}