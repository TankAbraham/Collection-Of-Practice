/*
 * 找零钱问题 - 贪心法能得到最优解或近似最优解
 */
#include <iostream>
#include <initializer_list>
#include <map>
#include <functional>

using namespace std;

struct Stratrgy{
	map<int, int, greater<int>> m;

	Stratrgy(initializer_list<int> l) {
		for (auto e : l) {
			m[e] = 0;
		}
	}
};

void change(int total, Stratrgy& s) {
	for (auto &e : s.m) {
		int n = 0;
		while ((total - (n+1) * e.first) >= 0){
			n++;
		}

		total -= n*e.first;
		e.second = n;
	}
}

void printStrategy(const Stratrgy& s) {
	for (auto e : s.m) {
		cout << e.first << " " << e.second << endl;
	}
}

int main() {
	Stratrgy s({25, 10, 5, 1});

	change(41, s);
	printStrategy(s);

	change(67, s);
	printStrategy(s);


	Stratrgy s2({ 100, 20, 10, 5, 1 });

	change(241, s2);
	printStrategy(s2);

	return 0;
}