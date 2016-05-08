#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

struct CountString {
	CountString(const string::size_type len):length(len) {}
	void operator() (const string& s) {
		if (s.size() == length)
			times++;
	}
	int times = 0;
	string::size_type length;
};

int main() {
	ifstream fin("data1.dat");

	vector<string> v;
	string s;
	while (fin >> s) 
		v.push_back(s);

	for (int i = 1; i < 7; i++) {
		CountString cs(i);
		for (auto &e : v)
			cs(e);
		cout << i << " 该长度的字符串出现 " << cs.times << endl;
	}
	
	return 0;
}
