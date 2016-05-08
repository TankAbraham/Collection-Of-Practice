#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
	ifstream fin("data5.dat");
	
	vector<int> v(11, 0);
	int num;
	while (fin >> num){
		cout << num << " ";
		++v[num / 10];
	}

	cout << endl;

	for (auto n : v)
		cout << n << " ";

	return 0;
}