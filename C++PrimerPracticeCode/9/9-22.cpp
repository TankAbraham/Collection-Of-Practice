#include <vector>
#include <iostream>

using namespace std;

int main(){
	int some_val = 2;
	vector<int> iv{ 1, 2, 3 };
	vector<int>::iterator iter = iv.begin(),
						mid = iv.begin() + iv.size() /2;
	while (iter != mid)
	{
		if (*iter == some_val)
			iv.insert(iter, 2 * some_val);
	}

	for (auto e : iv)
		cout << e << " ";
	return 0;
}