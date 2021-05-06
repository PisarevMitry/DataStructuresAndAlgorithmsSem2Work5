#include "Task2.h"

int getPriority(char token) {
	switch (token) {
	case '^':
		return 3;
	case '*':
		return 2;
	case '/':
		return 2;
	case '+':
		return 1;
	case '-':
		return 1;
	case '(':
		return 0;
	case ')':
		return 0;
	}
	return -1;
}

string calculate_to_prefix(string input) {
	stack<char> operation;
	queue<char> queue;
	int priority;
	for (int i = input.size() - 1; i >= 0; i--) {
		priority = getPriority(input[i]);
		if (priority == -1) {
			queue.push(input[i]);
		}
		else if (operation.empty()) {
			operation.push(input[i]);
		}
		else if (input[i] == '(') {
			while (operation.top() != ')') {
				queue.push(operation.top());
				operation.pop();
			}
			operation.pop();
		}
		else if (input[i] == ')') {
			operation.push(input[i]);
		}
		else if (priority > getPriority(operation.top())) {
			operation.push(input[i]);
		}
		else if (priority <= getPriority(operation.top())) {
			while (priority <= getPriority(operation.top()))
			{
				queue.push(operation.top());
				operation.pop();
				if (operation.empty()) {
					break;
				}
			}
			operation.push(input[i]);
		}
	}
	while (!operation.empty()) {
		queue.push(operation.top());
		operation.pop();
	}
	string result = "";
	while (!queue.empty()) {
		result = queue.front() + result;
		queue.pop();
	}
	return result;
}
