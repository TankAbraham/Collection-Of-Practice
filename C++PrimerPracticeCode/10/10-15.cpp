#include <iostream>

using namespace std;

int main()
{
	int a = 10;
	auto f = [a](int lhs) {return a + lhs; };
	cout << f(20) << endl;
	return 0;
}