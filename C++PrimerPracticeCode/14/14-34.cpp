#include <iostream>
#include <string>

using namespace std;

struct Solution {
	string operator() (const string& first = "1st", const string& second = "2nd", const string& thrid = "3th") {
		if (first != "1st")
			return second;
		else
			return thrid;
	}
};

int main() {
	auto cb = Solution();
	cout << cb("feng") << endl;;
	cout << cb("1st") << endl;;
	return 0;
}
