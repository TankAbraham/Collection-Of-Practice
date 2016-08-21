#include <iostream>
#include <queue>

using namespace std;

struct Node {
	Node(int v) :left(nullptr), right(nullptr), val(v) {}
	struct Node *left;
	struct Node* right;
	int val;
};

void levelVisit(queue<struct Node*> &que) {
	if (que.empty())	return;

	struct Node *p = que.front();	que.pop();

	if (p == nullptr)	return;

	cout << p->val << " ";

	que.push(p->left);
	que.push(p->right);

	levelVisit(que);
}

int main() {
	struct Node * root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);

	queue<struct Node*> que;
	que.push(root);

	levelVisit(que);

	return 0;
}