/*
 * 《编程之美》3.8 求二叉树中节点的最大距离
 * 不够完美的递归式解法
 */
#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
	int depth = 0;
	int distence = 0;
	struct Node *left = nullptr;
	struct Node *right = nullptr;
};

struct Result {
	Result(int dis, int dep) : distence(dis), depth(dep) {}
	int distence;
	int depth;
};

Result getMaxDistence(struct Node* p) {
	if (p == nullptr) {
		Result empty(0, -1); //trick：-1 用来中和叶子节点的高度
		return empty;
	}
	else {
		Result lhs = getMaxDistence(p->left);
		Result rhs = getMaxDistence(p->right);

		int distence = max(lhs.distence, rhs.distence);
		int depth = max(lhs.depth, rhs.depth) + 1;

		distence = max(lhs.depth + rhs.depth + 2, distence);

		Result ret(distence, depth);
		return ret;
	}
}

int main() {
	struct Node* root = new Node();
	root->left = new Node();
	root->left->left = new Node();
	root->left->left->left = new Node();
	root->left->left->right = new Node();
	root->left->right = new Node();
	root->left->right->right = new Node();

	cout << getMaxDistence(root).distence << endl;
	return 0;
}

//int main() {
//	struct Node* root = new Node();
//	root->left = new Node();
//	root->right = new Node();
//	cout << getMaxDistence(root).distence<< endl;
//	return 0;
//}

//int main() {
//	struct Node* root = new Node();
//	root->left = new Node();
//
//	cout << getMaxDistence(root).distence<< endl;
//	return 0;
//}

//int main() {
//	struct Node *root = new Node();
//	root->left = new Node();
//	root->left->right = new Node();
//	root->left->left = new Node();
//	root->right = new Node();
//	root->right->right = new Node();
//
//	cout << getMaxDistence(root).distence<< endl;
//
//	return 0;
//}