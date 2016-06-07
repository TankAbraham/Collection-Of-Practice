/*
 * 网易云课堂 c++ 算法原理与实践 栈与队列的应用
 */

#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

 queue<char> inOrder2Postfix(const string inOrderExpression) {
	stack<char> operatorStack;
	queue<char> postfixExpression;

	for (string::size_type i = 0; i < inOrderExpression.length(); i++) {
		char c = inOrderExpression[i];

		switch (c)
		{
		case '+':
		case '-':
			while (operatorStack.top() == '*' || operatorStack.top() == '/' 
				|| operatorStack.top() == '+' || operatorStack.top() == '-') 
			{
				postfixExpression.push(operatorStack.top());
				operatorStack.pop();
			}
			operatorStack.push(c);
			break;
		case '*':
		case '/':	//if top() > currentOperator then pop()
			if (operatorStack.empty()) {
				operatorStack.push(c);
				break;
			}

			if (operatorStack.top() == '+' || operatorStack.top() == '-') {
				operatorStack.push(c);
				break;
			}
			
			if(operatorStack.top() == '(') {
				operatorStack.push(c);
				break;
			}
			
			if (operatorStack.top() == '*' || operatorStack.top() == '/') {
				postfixExpression.push(operatorStack.top());
				operatorStack.pop();
				operatorStack.push(c);
				break;
			}
			
		case '(':
			operatorStack.push(c);
			break;
		case ')':
			while (operatorStack.top() != '(') {
				postfixExpression.push(operatorStack.top());
				operatorStack.pop();
			}
			
			if (operatorStack.top() == '(')
				operatorStack.pop();

			break;
		default:	//digital
			postfixExpression.push(c);
			break;
		}
	}

	while (!operatorStack.empty()) {
		postfixExpression.push(operatorStack.top());
		operatorStack.pop();
	}

	return postfixExpression;
}

double evaluateExpression(const string expression) {
	queue<char> postfixExpression = inOrder2Postfix(expression); //先将中缀转化为后缀
	stack<double> number;

	double lhs = 0;
	double rhs = 0;

	while (!postfixExpression.empty()) {
		char c = postfixExpression.front();
		postfixExpression.pop();
		switch (c)
		{
		case '+':
			rhs = number.top(); 
			number.pop();
			lhs = number.top();
			number.pop();
			number.push(lhs + rhs);
			break;
		case '-':
			rhs = number.top();
			number.pop();
			lhs = number.top();
			number.pop();
			number.push(lhs - rhs);
			break;
		case '*':
			rhs = number.top();
			number.pop();
			lhs = number.top();
			number.pop();
			number.push(lhs * rhs);
			break;
		case '/':
			rhs = number.top();
			number.pop();
			lhs = number.top();
			number.pop();
			number.push(lhs / rhs);
			break;
		default:
			number.push(c - 48);
			break;
		}
	}

	return number.top();
}

int main() {
	string s = "(4+5)*(7-2)";
	double result = evaluateExpression(s); 
	cout << result << endl;

	s = "4*5/7";
	result = evaluateExpression(s);
	cout << result << endl;

	return 0;
}