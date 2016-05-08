#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str("feng yu bo");
	for (char &c : str)
		c = 'X';

	for (auto c : str)
		cout << c;
	return 0;
}