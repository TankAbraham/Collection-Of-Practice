#include <vector>
#include <list>
#include <iostream>

using namespace std;

int main()
{
	vector<int> v1{1, 2, 3};
	list<int> l1{ 1, 2 };
	if(*v1.cbegin() == *l1.cbegin())
		cout << "equal" << endl;
	return 0;
}