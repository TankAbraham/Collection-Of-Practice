#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <cstdlib>

using namespace std;

class CalculatePostfix
{
public:
	int operator()(const string postfix)
	{
		istringstream iss(postfix);

		string s;

		int sum;

		while (iss >> s)
		{
			if (isOperator(s))
			{
				int rhs = sk.top();	sk.pop();
				int lhs = sk.top();	sk.pop();

				sum = calculate(s, lhs, rhs);

				sk.push(sum);
			}
			else
				sk.push(atoi(s.c_str()));
		}

		return sk.top();
	}

private:
	bool isOperator(string c) const
	{
		if (c == "+" || c == "-" || c == "*" || c == "/")
			return true;
		else
			return false;
	}

	int calculate(const string &s, const int lhs, const int rhs) const 
	{
		if (s == "+")
			return lhs + rhs;
		if (s == "-")
			return lhs - rhs;
		if (s == "*")
			return lhs * rhs;
		if (s == "/")
			return lhs / rhs;

		return 0;
	}

	stack<int> sk;
};

class Infix2Postfix
{
public:
	string operator()(const string &s)
	{
		istringstream iss(s);

		string c;

		while (iss >> c)
		{
			if (isOperator(c) == 0)
			{
				output.append(c).append(" ");
				continue;
			}

			switch (isOperator(c))
			{
			case 1:
			case 2:
			case 3:
				popWhileLow(isOperator(c));
				sk.push(c);
				break;
			case 4:
				popWhileNoLeftBracket();
				break;
			}
		}

		while (!sk.empty())
		{
			output.append(sk.top());
			output.append(" ");
			sk.pop();
		}

		return output;
	}
private:
	void popWhileLow(const int op)
	{
		if (sk.empty()) return;

		while (op > isOperator(sk.top()))
		{
			output.append(sk.top());
			sk.pop();
		}

		if (sk.top() != "(")
		{
			output.append(sk.top()); output.append(" ");
			sk.pop();
		}
	}

	void popWhileNoLeftBracket()
	{
		if (sk.empty()) return;

		while (sk.top() != "(")
		{
			output.append(sk.top()); output.append(" ");
			sk.pop();
		}

		sk.pop();
	}

	int isOperator(const string &s) const
	{
		if (s == "+" || s == "-")
			return 1;
		if (s == "*" || s == "/")
			return 2;
		if (s == "(")
			return 3;
		if (s == ")")
			return 4;

		return 0;
	}

	stack<string> sk;
	string output;
};

int main()
{
	string infix = "( ( 2 + 3 ) * 8 + 5 + 3 ) * 6";
	string postfix = "2 3 + 8 * 5 + 3 + 6 *";

	CalculatePostfix cp;
	Infix2Postfix i2p;

	cout << cp(postfix) << endl;
	cout << i2p(infix) << endl;
	cout << cp(i2p(infix)) << endl;
	
	return 0;
}