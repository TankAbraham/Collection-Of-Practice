#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <queue>

using namespace std;

struct Character {
	Character(unsigned freq = 0) : c(NULL), frequence(freq), left(nullptr), right(nullptr), huffmanCode("") {}
	char c;
	unsigned frequence;	//频率，权
	struct Character *left;
	struct Character *right;
	string huffmanCode;
	char direction;
};

map<char, Character> fileToFrequence(const string &name) {
	ifstream ifs(name);
	map<char, Character> codePlan;

	char c;
	while (ifs.get(c)) {
		codePlan[c].c = c;
		codePlan[c].frequence++;
	}

	return codePlan;
}

struct CompareWeight {
	bool operator() (const Character &lhs, const Character &rhs) const
	{
		return lhs.frequence > rhs.frequence ? true : false;
	}
};

struct Character* huffman(priority_queue<Character, vector<Character>, CompareWeight> &heap) {
	struct Character *root = nullptr;

	while (!heap.empty()) {
		root = new Character();
		Character temp = heap.top();

		temp.direction = '0';
		root->left = new Character();
		*root->left = temp;
		heap.pop();
		if (heap.empty()) {
			root = root->left;
			break;
		}
		else {
			temp = heap.top();
			temp.direction = '1';
			root->right = new Character();
			*root->right = temp;
			heap.pop();
		}

		root->frequence = root->left->frequence + root->right->frequence;
		heap.push(*root);
	}

	return root;
}

//字符集一般是常数级的数量级，所以这里使用递归不至于爆栈
void huffmanTreeToCode(struct Character* root, string path, map<char, Character>& codePlan) {
	if (root->c == NULL) {
		//left node
		string leftPath = path + "0";
		huffmanTreeToCode(root->left, leftPath, codePlan);

		string rightPath = path + "1";
		huffmanTreeToCode(root->right, rightPath, codePlan);
	}
	else {
		codePlan[root->c].huffmanCode = path;
	}
}

void buildHeap(priority_queue<Character, vector<Character>, CompareWeight>& heap, const map<char, Character>& codePlan) {
	for (auto e : codePlan) {
		heap.push(e.second);
	}
}

int main() {
	map<char, Character> codePlan = fileToFrequence("huffman_test.txt");
	priority_queue<Character, vector<Character>, CompareWeight> heap;

	buildHeap(heap, codePlan);

	struct Character *root = huffman(heap);

	huffmanTreeToCode(root, string(), codePlan);

	for (auto e : codePlan) {
		cout << e.first << " " << e.second.huffmanCode << endl;
	}

	return 0;
}