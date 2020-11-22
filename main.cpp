/*** Mohammad Musawer -- Stack Calculator ***/
#include<iostream>
#include"Stack.h"
#include<cctype>
#include<string>
using namespace std;
int prec(char c)
{
	if (c == '*' || c == '/')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}
bool isInputValid(string input) {
	if (input[0] == '(' || input[0] == 'e'|| isdigit(input[0]))
		return 1;
	return 0;
}
string infixToPostfix(string infix)
{
	string postfix;
	Stack<char> stack;
	int len = infix.length();
	for (int i = 0; i < len; i++)
	{
		if (isdigit(infix[i]))
			postfix += infix[i];

		else if (infix[i] == '(')
			stack.push('(');

		else if (infix[i] == ')')
		{
			while (!stack.empty() && stack.getTop() != '(')
			{
				char c = stack.getTop();
				stack.pop();
				if(c!='(')
					postfix += c;
			}
			if (stack.getTop() == '(')
			{
				char c = stack.getTop();
				if(!stack.empty())
					stack.pop();
			}
		}
		else if(infix[i]=='*'|| infix[i] == '/' || infix[i] == '+' || infix[i] == '-') {
			while (!stack.empty() && prec(infix[i]) <= prec(stack.getTop()))
			{
				char c = stack.getTop();
				stack.pop();
				postfix += c;
			}
			stack.push(infix[i]);
		}
	}
	while (!stack.empty())
	{
		char c = stack.getTop();
		stack.pop();
		postfix += c;
	}
	return postfix;
}
int evaluatePostfix(string exp)
{
	Stack<int> stack;

	for (int i = 0; exp[i]; ++i)
	{
		if (isdigit(exp[i])) {
			stack.push(exp[i] - '0');
		}
		else {
			int val1 = stack.getTop();
			stack.pop();
			int val2 = stack.getTop();
			stack.pop();
			switch (exp[i])
			{
				case '-': stack.push(val2 - val1); break;
				case '*': stack.push(val2 * val1); break;
				case '/': stack.push(val2 / val1); break;
				case '+': stack.push(val2 + val1); break;
			}
		}
	}
	return stack.getTop();
}
int main() {

	string input;
	string postfix;

	do
	{
		cout << "Enter expression (or exit to end): ";
		getline(cin, input);

		if (!isInputValid(input)) {
			cout << "Invalid expression" << endl;
			continue;
		}
		if (input.compare("exit")==0) {
			cout << "Exiting program ..." << endl;
			exit(0);
		}
		cout << "Expression: " << input << endl;

		postfix = infixToPostfix(input);
		cout << "Postfix form: ";
		for (int i = 0; i < postfix.length(); i++) {
			cout << postfix[i] << ' ';
		}
		cout << endl;
		cout << "Result: " << evaluatePostfix(postfix) << endl;

	} while (true);



	return 0;
}
