#include <iostream>
#include <vector>

using namespace std;

template <typename T>
ostream& foreachPrint1(ostream& os, const T& c)
{
	//typedef typename T::size_type sz;
	for (typename T::size_type i = 0; i != c.size(); i++)
		os << c[i];
	return os;
}

template <typename T>
ostream& foreachPrint2(ostream& os, const T& c)
{
	T::const_iterator cit = c.cbegin();
	for (typename T::size_type i = 0; i != c.size(); i++)
		os << *cit++;
	return os;
}

int main() 
{
	vector<int> v = { 1, 2, 3 };

	foreachPrint1<vector<int>>(cout, v);
	foreachPrint2<vector<int>>(cout, v);

	return 0;
}