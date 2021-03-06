/*
 * 近似装箱问题 - 联机算法 - 下项适合算法
 */
#include <iostream>
#include <vector>

using namespace std;

template<typename T>
struct Boxes {
	Boxes(T quality = 10) : rest(quality), maxQuality(quality) {}
	T rest;
	const T maxQuality;
	vector<T> v;
};

void nextFit(vector<Boxes<int>> &boxes, int curr) {
	if (curr > boxes[0].maxQuality)
		cout << "error : exceed max quality" << endl;

	if (boxes[boxes.size() - 1].rest - curr >= 0){
		boxes[boxes.size() - 1].rest -= curr;
		boxes[boxes.size() - 1].v.push_back(curr);
	}
	else {
		boxes.push_back(Boxes<int>());
		boxes[boxes.size() - 1].rest -= curr;
		boxes[boxes.size() - 1].v.push_back(curr);
	}
}

void visitBoxes(const vector<Boxes<int>>& v) {
	for (auto box : v) {
		cout << box.rest << "\t";
		for (auto e : box.v) {
			cout << e << " ";
		}
		cout << endl;
	}
}

int main() {
	vector<Boxes<int>> v(1);
	int curr;

	while (cin >> curr) {
		nextFit(v, curr);
		visitBoxes(v);
	}
}