#include <iostream>
#include <string>
#include <map>
#include <queue>

using namespace std;

struct Node {
	Node(int freq = 0, char c = NULL) 
		: frequnce(freq), left(nullptr), right(nullptr), val(c) {}

	int frequnce;
	struct Node* left;
	struct Node* right;
	char val;
};

string getInput() {
	string line;

	cout << "pleast input some text" << endl;
	cin >> line;

	return line;
}

map<char, int> statisticsFrequence(const string& s) {
	map<char, int> frquence;

	for (auto e : s) {
		frquence[e]++;
	}

	return frquence;
}

struct Compare {
	bool operator() (const struct Node* lhs, const struct Node* rhs) const {
		return lhs->frequnce > rhs->frequnce; //最小堆
	}
};

struct Node* buildHuffmanTree(const map<char, int> &frequence) {
	priority_queue<struct Node*, vector<struct Node*>, Compare> minHeap;

	for (auto e : frequence) {
		minHeap.push(new struct Node(e.second, e.first));
	}

	while (minHeap.size() > 1) {
		struct Node* root = new struct Node();

		root->left = minHeap.top();
		minHeap.pop();

		root->right = minHeap.top();
		minHeap.pop();

		root->frequnce = root->left->frequnce + root->right->frequnce;

		minHeap.push(root);
	}

	return minHeap.top();
}

void treeToCode(struct Node* root, string& path, map<char, string>& codePlan) {
	if (root->val == NULL) {
		string leftPath = path + "0";
		treeToCode(root->left, leftPath, codePlan);

		string rightPath = path + "1";
		treeToCode(root->right, rightPath, codePlan);
	}
	else {
		codePlan[root->val] = path;
	}
}

int main() {
	string s = getInput();
	map<char, int> frequence = statisticsFrequence(s);
	struct Node* root = buildHuffmanTree(frequence);

	map<char, string> codePlan;
	treeToCode(root, string(), codePlan);

	for (auto e : codePlan) {
		cout << e.first << ' ' << e.second << endl;
	}

	return 0;
}