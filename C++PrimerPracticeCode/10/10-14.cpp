#include <iostream>

using namespace std;

int main()
{
	auto f = [](int lhs, int rhs) { return lhs + rhs; };
	cout << f(1, 2) << endl;
	return 0;
}