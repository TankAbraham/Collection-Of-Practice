#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int firstUniqChar(string s) {
		unordered_map<char, unsigned int> crmap;
		unordered_map<char, unsigned int> cimap;

		for (size_t i = 0; i < s.size(); i++) {
			crmap[s[i]]++;
			cimap[s[i]] = i;
		}

		char c = NULL;
		string::iterator it = s.begin();
		while (it != s.end()) {
			if (crmap[*it] == 1) {
				c = *it;
				break;
			}
			it++;
		}

		return (c == NULL) ? -1 : cimap[c];
	}
};

int main() {
	Solution so;
	string s;

	s = "leetcode";
	cout << so.firstUniqChar(s) << endl;

	s = "loveleetcode";
	cout << so.firstUniqChar(s) << endl;

	return 0;
}