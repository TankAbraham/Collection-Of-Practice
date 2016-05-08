#include <iostream>
#include <string>

using namespace std;

istream& foo(istream& is)
{
	string s;

	while (is >> s)
		cout << s << endl;

	is.clear();

	return is;
}

int main()
{
	foo(cin);

	return 0;
}