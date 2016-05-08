#include <iostream>
#include <vector>


using namespace std;


template<typename I, typename T>
I find(I  &beg, I &end, const T &val){
	I it = beg;
	while (it != end){
		if (*it == val)
			return it;
		else
			++it;
	}
}

int main(){
	vector<int> v = { 1, 2, 3, 4, 5 };
	cout << find(v.cbegin(), v.cend(), 3) - v.begin();

	return 0;
}