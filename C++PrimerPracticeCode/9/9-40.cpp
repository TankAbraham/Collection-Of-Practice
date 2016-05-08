#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<int> v;
	const int length = 1048; // 256	512	1000
	for (int i = 0; i < length; i++)
		v.push_back(i);
	v.reserve(v.size() + v.size() / 2);
	cout << "size: " << v.size() << " " << v.capacity() << endl;

	return 0;
}