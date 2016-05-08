#include <vector>
#include <list>
#include <iostream>

using namespace std;

int main()
{
	char *pc = "feng";
	char *pc2 = pc + 1;
	list<char*> lst{ pc, pc2 };
	vector<char*> v(lst.cbegin(), lst.cend());
	cout << v[0] << v[1];
	return 0;
}