#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

bool check_size(const string& s, string::size_type sz)
{
	return s.size() < sz;
}

int main()
{
	ifstream fin("data3.dat");

	vector<int> numbers;
	int num;
	while (fin >> num)
		numbers.push_back(num);

	auto it1 = find_if(numbers.cbegin(), numbers.cend(), bind(check_size, "feng", placeholders::_1));
	auto it2 = find_if(numbers.cbegin(), numbers.cend(), bind(check_size, "yu", placeholders::_1));

	cout << *it1 << endl;
	cout << *it2 << endl;

	return 0;
}