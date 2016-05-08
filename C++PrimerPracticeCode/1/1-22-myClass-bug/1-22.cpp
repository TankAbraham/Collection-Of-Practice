#include "Sales_data.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>

using namespace std;

class Sales_data;
class Sales_data_add
{
public:
	Sales_data operator() (const Sales_data& lhs, const Sales_data& rhs)
	{
		Sales_data ret = lhs + rhs;
		return ret;
	}
};

int main()
{
	ifstream fin("data2.dat");
	vector<Sales_data> v;
	Sales_data item;
	while (fin >> item)
		v.push_back(item);

	cout << accumulate(v.cbegin(), v.cend(), item,
				[](const Sales_data& lhs, const Sales_data& rhs)
					{
						return lhs + rhs;
					});

	//cout << accumulate(v.begin(), v.end(), item, Sales_data_add());

	return 0;
}