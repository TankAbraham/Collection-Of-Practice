#include <iostream>
#include <vector>

using namespace std;

vector<int>* factory(initializer_list<int> il) {
	return new vector<int>(il);
}

void setValue(vector<int>* p, istream& in) {
	int temp;
	while (in >> temp  &&  temp != 999)
		p->push_back(temp);
}

void print(vector<int>* p) {
	for (auto e : *p)
		cout << e;
}

int main() {
	vector<int> *p = factory({ 1, 2, 3 });

	vector<int> *p2 = new vector<int>();
	setValue(p2, cin);


	print(p);
	print(p2);

	delete p;
	delete p2;
	return 0;
}