#include <vector>
#include <list>
#include <iostream>

using namespace std;

int main(){
	int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };

	vector<int> v(ia, end(ia));
	list<int> l(ia, end(ia));

	auto iv = v.begin();
	while (iv != v.end()) {
		if ( !(*iv % 2) )
			iv = v.erase(iv);
		else
			++iv;
	}

	auto il = l.begin();
	while (il != l.end())
	{
		if ( *il % 2 )
			il = l.erase(il);
		else
			++il;
	}

	for (auto ev : v)
		cout << ev << " ";
	
	cout << endl;
	
	for (auto el : l)
		cout << el << " ";

	return 0;
}