#include <vector>
#include <list>
#include <iostream>

using namespace std;

int main()
{
	vector<int> v1{1, 2, 3};
	vector<int> v2{ 3, 2, 1 };
	vector<int> v3{ 1, 2, 3 };
	if(v1 == v2)
		cout << "equal" << endl;
	if(v1 == v3)
		cout << "v1 equal to v3" << endl;
	return 0;
}