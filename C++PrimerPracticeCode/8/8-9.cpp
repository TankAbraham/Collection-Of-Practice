#include <iostream>
#include <string>
#include <sstream>

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
	ostringstream msg;
	msg << "冯 煜 博" << endl;
	istringstream in(msg.str());

	foo(in);

	return 0;
}