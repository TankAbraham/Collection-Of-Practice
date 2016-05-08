#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<int> v;
	for (int i = 0; i < 50; i++) {
		v.push_back(i);
		cout << "size: " << v.size() << " " << v.capacity() << endl;
	}
	return 0;
}