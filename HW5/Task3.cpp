#include "Task3.h"

string calculate_brackets(string input, bool mode) {
	string result = "";
	stack<int> brackets;
	if (mode) {
		for (int i = input.size() - 1; i >= 0; i--) {
			if (input[i] == ')') {
				brackets.push(i + 1);
			}
			else if (input[i] == '(') {
				result = to_string(i + 1) + " " + to_string(brackets.top()) + "; " + result;
				brackets.pop();
			}
		}
	}
	else
	{
		for (int i = 0; i < input.size(); i++) {
			if (input[i] == '(') {
				brackets.push(i + 1);
			}
			else if (input[i] == ')') {
				result = result + to_string(brackets.top()) + " " + to_string(i + 1) + "; ";
				brackets.pop();
			}
		}
	}
	return result;
}
