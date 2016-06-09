/*
 * 网易云课堂 算法设计与实践 Extension How to calculate (12+3) * (3+2)^2
 * 多位数运算 + 幂运算
 */
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <sstream>
#include <cmath>

using namespace std;

#define OP 1
#define NUM 2

#define ADD "+"
#define SUB "-"
#define MUL "*"
#define DIV "/"

#define LONG 21
#define DOUBLE 22


struct Word {
	Word(const string word) : val(word) {
		if (word == "+" || word == "-" || word == "*" || word == "/" || word == "(" || word == ")" || word == "^") {
			type = OP;
		}
		else {
			type = NUM;
		}
	}
	int type;
	string val;
	const map<const string, int> m = {
		{ "(", 1 },
		{ "+", 2 },
		{ "-", 2 },
		{ "*", 3 },
		{ "/", 3 },
		{ "^", 3 }
	};
};

bool operator==(const Word &lhs, const int rhs) {
	return lhs.type == rhs;
}

bool operator> (const Word &lhs, const Word &rhs) {
	if (lhs.type == OP && rhs.type == OP) {
		return lhs.m.at(lhs.val) - rhs.m.at(rhs.val) >= 0 ? true : false;
	}
	return false;
}

bool operator== (const Word &lhs, const string rhs) {
	return lhs.val == rhs;
}

vector<Word> inorder2Postorder(const vector<Word> &v) {
	stack<Word> st;

	vector<Word> postfix;

	vector<Word>::const_iterator it = v.cbegin();
	while (it != v.cend()) {
		if (*it == NUM) {
			postfix.push_back(it++->val);
			continue;
		}
		if (*it == "(") {
			st.push(*it++);
			continue;
		}
		if (*it == ")") {
			while (!st.empty() && st.top().val != "(") {
				postfix.push_back(st.top());
				st.pop();
			}
			st.pop();
			it++;
			continue;
		}
		while (!st.empty() && st.top() > *it) {
			postfix.push_back(st.top());
			st.pop();
		}

		st.push(*it++);
	}

	while (!st.empty()) {
		postfix.push_back(st.top().val);
		st.pop();
	}

	return postfix;
}

vector<Word> str2Words(const string &exp) {
	string::const_iterator it = exp.cbegin();
	string line;

	while (it != exp.cend()) {
		if (*it == '+' ||
			*it == '-' ||
			*it == '*' ||
			*it == '/' ||
			*it == '(' ||
			*it == ')' ||
			*it == '^')
		{
			line += " ";
			line += *it;
			line += " ";
		}
		else {
			line += *it;
		}
		it++;
	}

	vector<Word> v;
	istringstream iss(line);
	string word;
	while (iss >> word) {
		v.push_back(word);
	}

	return v;
}

double calculatePostfix(const vector<Word> v) {
	vector<Word>::const_iterator it = v.cbegin();
	stack<double> st;
	double lhs, rhs;

	while (it != v.cend()) {
		if (*it == "*") {
			rhs = st.top(); st.pop();
			lhs = st.top(); st.pop();
			lhs = lhs * rhs;
			st.push(lhs);
		}
		else if (*it == "/") {
			rhs = st.top(); st.pop();
			lhs = st.top(); st.pop();
			lhs = lhs / rhs;
			st.push(lhs);
		}
		else if (*it == "+") {
			rhs = st.top(); st.pop();
			lhs = st.top(); st.pop();
			lhs = lhs + rhs;
			st.push(lhs);
		}
		else if (*it == "-") {
			rhs = st.top(); st.pop();
			lhs = st.top(); st.pop();
			lhs = lhs - rhs;
			st.push(lhs);
		}
		else if (*it == "^") {
			rhs = st.top(); st.pop();
			lhs = st.top(); st.pop();
			lhs = pow(lhs, rhs);
			st.push(lhs);
		}
		else {
			if (it->val.find(".") == string::npos) {
				st.push(atol(it->val.c_str()));
			}
			else {
				st.push(atof(it->val.c_str()));
			}
		}
		it++;
	}
	
	return st.top();
}

int main() {
	string exp;
	vector<Word> inorderExp;
	vector<Word> postfix;

	//exp = "4+3*(2.5+1)";
	//inorderExp = str2Words(exp);
	//postfix = inorder2Postorder(inorderExp);
	//cout << calculatePostfix(postfix) << endl;

	//exp = "3+14*5";
	//inorderExp = str2Words(exp);
	//postfix = inorder2Postorder(inorderExp);
	//cout << calculatePostfix(postfix) << endl;

	exp = "(3+2)^2*(12+3)";
	inorderExp = str2Words(exp);
	postfix = inorder2Postorder(inorderExp);
	cout << calculatePostfix(postfix) << endl;

	return 0;
}