#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
	ifstream fin("data3.dat");
	vector<int> numbers;
	int num;
	while (fin >> num)
		numbers.push_back(num);

	for_each(numbers.begin(), numbers.end(),[](int &i) {i = i * 2;});

	for_each(numbers.cbegin(), numbers.cend(), [](const int i) {cout << i << " "; });

	return 0;
}