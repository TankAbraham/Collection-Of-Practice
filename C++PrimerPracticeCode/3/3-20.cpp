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

	int iBeg = 0;
	int iEnd = v.size();
	iEnd--;

	while (iBeg <= iEnd) 
	{
		cout << v.at(iBeg) <<  " + " << v.at(iEnd) << " = " << v.at(iBeg) + v.at(iEnd) << endl;
		++iBeg;
		--iEnd;
	}


	//第二种方法
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