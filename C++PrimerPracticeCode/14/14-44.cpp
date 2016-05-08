#include <iostream>
#include <functional>
#include <list>
#include <map>
#include <fstream>
#include <stack>

using namespace std;

ostream& operator<<(ostream& os, list<char>& l) {
	for (auto &e : l)
		os << e << " ";
	return os;
}

void convert(list<char>& l) {
	char c;
	stack<char> st;
	stack<char> stTemp;
	while (l.size()) {
		c = l.back();
		l.pop_back();
		switch (c)
		{
		case '+':
		case '-':
		case '*':
		case '/':
			// 如果最后一个字符是操作符，则应该报错
			//但是这个版本不作处理
			stTemp.push(st.top());
			st.pop();
			st.push(c);
			st.push(stTemp.top());
			stTemp.pop();
			break;
		default:	// 数字
			st.push(c);
			break;
		}
	}
	while (st.size()) {
		l.push_back(st.top());
		st.pop();
	}
}

map<char, function<int(int, int)>> binops = {
	{ '+', plus<int>() },
	{ '-', minus<int>() },
	{ '*', multiplies<int>() },
	{ '/', divides<int>() } };

void calculate(list<char>& l) {
	stack<char> st;
	char c;
	int lhs, rhs;
	while (l.size()){
		c = l.front();
		l.pop_front();
		switch (c)
		{
		case '+':
		case '-':
		case '*':
		case '/':
			rhs = (int)st.top();
			st.pop();
			lhs = (int)st.top();
			st.pop();
			st.push(binops[c](lhs, rhs));
			break;
		default:	// 数字
			st.push((int)c - 48);
			break;
		}
	}
	l.push_back(st.top());
}

int main() {
	list<char> l;
	ifstream fin("data8.dat");
	char c;
	
	while (fin >> c)
		l.push_back(c);

	convert(l);
	cout << l << endl;
	calculate(l);
	cout << (int)l.back() << endl;
	return 0;
}