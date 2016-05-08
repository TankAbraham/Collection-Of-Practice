#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
	ifstream fin("data3.dat");
	vector<int> v;
	int n;
	while (fin >> n)
		v.push_back(n);

	vector<int>::iterator itBeg = v.begin();
	vector<int>::iterator itEnd = v.end();
	itEnd--;

	while (itBeg < itEnd)
	{
		cout << *itBeg << " + " << *itEnd << " = " << *itBeg + *itEnd << endl;
		++itBeg;
		--itEnd;
	}

	return 0;
}