#include <iostream>

using namespace std;

int main()
{
	int i = 0, &r1 = i;
	double d = 0, &r2 = d;

	//r2 = 3.1415926;
	//cout << r2 << " " << d << endl;

	//r2 = r1;
	//cout << r2 << " " << r1 << " " << d << endl;

	//i = r2;
	//cout << r2 << " " << r1 << " " << d << endl;

	//r1 = d;
	//cout << r1 << " " << d;

	return 0;
}