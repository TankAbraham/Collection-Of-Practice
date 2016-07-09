/*
 * 近似装箱问题 - 联机算法 - 首次适合算法
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

void firstFit(vector<Boxes<int>> &boxes, int curr) {
	if (curr > boxes[0].maxQuality)
		cout << "error : exceed max quality" << endl;

	for (auto &box : boxes) {
		if (box.rest - curr >= 0) {
			box.rest -= curr;
			box.v.push_back(curr);
			return;
		}
	}

	boxes.push_back(Boxes<int>());
	boxes[boxes.size() - 1].rest -= curr;
	boxes[boxes.size() - 1].v.push_back(curr);
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
		firstFit(v, curr);
		visitBoxes(v);
	}
}