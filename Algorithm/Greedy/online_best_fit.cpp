/*
 * 近似装箱问题 - 联机算法 - 最佳适合算法
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

void bestFit(vector<Boxes<int>> &boxes, int curr) {
	if (curr > boxes[0].maxQuality) {
		cout << "error : out of max quality" << endl;
		return;
	}

	size_t fitNo = -1;
	int fitRest = boxes[0].maxQuality;

	for (size_t i = 0; i < boxes.size(); i++) {
		int curRest = boxes[i].rest - curr;

		if (fitRest > curRest && curRest >= 0) {
			fitRest = curRest;
			fitNo = i;
		}
	}

	if (fitNo == -1 && fitRest == boxes[0].maxQuality) {
		boxes.push_back(Boxes<int>());
		boxes[boxes.size() - 1].rest -= curr;
		boxes[boxes.size() - 1].v.push_back(curr);
	}
	else {
		boxes[fitNo].v.push_back(curr);
		boxes[fitNo].rest -= curr;
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
		bestFit(v, curr);
		visitBoxes(v);
	}
}