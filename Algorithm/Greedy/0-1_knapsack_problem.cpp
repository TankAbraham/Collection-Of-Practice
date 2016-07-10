/*
 * 0-1 背包问题 - 贪心算法
 * 遗憾：没能实现函数/仿函数的数组化；没能实现使用可调用对象作为函数参数使用。
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Goods {
	Goods(int w, int p) : weight(w), price(p) {}
	int weight;
	int price;
};

struct Package {
	int rest = 150;
	int price = 0;
	vector<Goods> collection;
};

Package packingProblem(const vector<Goods>& goods) {
	Package package;

	for (size_t i = 0; i < goods.size(); i++) {
		if (package.rest - goods[i].weight >= 0) {
			package.rest -= goods[i].weight;
			package.price += goods[i].price;
			package.collection.push_back(goods[i]);
		}
		else
			break;
	}

	return package;
}

int main() {
	vector<Goods> goods = {
		{ 35, 10 },
		{ 30, 40 },
		{ 60, 30 },
		{ 50, 50 },
		{ 40, 35 },
		{ 10, 40 },
		{ 25, 30 },
	};

	vector<Package> v(3);

	sort(goods.begin(), goods.end(),
		[](const Goods& lhs, const Goods& rhs) {
		return lhs.price > rhs.price;
	});
	v[0] = packingProblem(goods);
	
	sort(goods.begin(), goods.end(),
		[](const Goods& lhs, const Goods& rhs) {
		return lhs.weight < rhs.weight;
	});
	v[1] = packingProblem(goods);

	sort(goods.begin(), goods.end(),
		[](const Goods& lhs, const Goods& rhs) {
		return (lhs.price / lhs.weight) > (rhs.price / rhs.weight);
	});
	v[2] = packingProblem(goods);

	sort(v.begin(), v.end(),
		[](const Package& lhs, const Package& rhs) {
		return lhs.price > rhs.price;
	});

	cout << v[0].price << endl;
	for (auto e : v[0].collection) {
		cout << e.weight << " ";
	}

	return 0;
}