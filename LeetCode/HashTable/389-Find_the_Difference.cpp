#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
	char findTheDifference(const string &s, const string &t) {
		map<char, int> m;

		for (size_t i = 0; i < s.length(); i++) {
			m[s[i]]++;
		}

		for (size_t i = 0; i < t.length(); i++) {
			if (--m[t[i]] <= 0) {
				return t[i];
			}
		}

		return 0;
	}
};

int main(){
	Solution so;

	string s = "abcd";
	string t = "abcde";

	cout << so.findTheDifference(s, t) << endl;

	return 0;
}