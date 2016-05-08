#include <vector>
#include <list>

using namespace std;

int main()
{
	list<int> l1;
	list<int> l2(l1);
	list<int> l3{ 1,2,3 };
	list<int> l4(l3.cbegin(), l3.cend());
	list<int> l5(3);
	list<int> l6(3, 1);
	return 0;
}