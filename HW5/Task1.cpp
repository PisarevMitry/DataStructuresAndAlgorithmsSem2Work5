#include "Task1.h"

bool isOperation(string token) {
	if (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/' || token[0] == '(' || token[0] == ')') {
		return true;
	}
	else {
		return false;
	}
}

string calculate(string var1, string sign, string var2) {
	float res = 0;
	if (sign[0] == '+') {
		res = stof(var1) + stof(var2);
	}
	else if (sign[0] == '-') {
		res = stof(var1) - stof(var2);
	}
	else if (sign[0] == '*') {
		res = stof(var1) * stof(var2);
	}
	else if (sign[0] == '/') {
		res = stof(var1) / stof(var2);
	}
	return to_string(res);
}

// Функция вычисления значения выражения для массива
// Предусловие: на вход поступает непустая строка
// Постусловие: возвращет значение выражения в виде строки
string calculate_array(string input) {
	string varToken, topToken, sign, var;
	ArrayQueue* queue;
	queue = new ArrayQueue(100);

	for (char i : input) {
		varToken = i;
		if (varToken == " ") {
			continue;
		}
		if (isOperation(varToken)) {
			queue->push(varToken);
			for (int i = 0; i < queue->size - 1; i++) {
				queue->push(queue->pop());
			}
			continue;
		}
		if (queue->size >= 1) {
			topToken = queue->pick();
			while (!isOperation(topToken)) {
				topToken = queue->pop();
				sign = queue->pop();
				varToken = calculate(topToken, sign, varToken);
				topToken = queue->pick();
			}
			queue->push(varToken);
			for (int i = 0; i < queue->size - 1; i++) {
				queue->push(queue->pop());
			}
		}
	}
	while (queue->size != 1) {
		varToken = queue->pop();
		topToken = queue->pop();
		sign = queue->pop();
		var = calculate(topToken, sign, varToken);
		queue->push(var);
		for (int i = 0; i < queue->size - 1; i++) {
			queue->push(queue->pop());
		}
	}
	return queue->pop();
}

// Функция вычисления значения выражения для списка
// Предусловие: на вход поступает непустая строка
// Постусловие: возвращет значение выражения в виде строки
string calculate_list(string input) {
	string varToken, topToken, sign, var;
	ListQueue* queue;
	queue = new ListQueue;

	for (char i : input) {
		varToken = i;
		if (varToken == " ") {
			continue;
		}
		if (isOperation(varToken)) {
			queue->push(varToken);
			for (int i = 0; i < queue->size - 1; i++) {
				queue->push(queue->pop());
			}
			continue;
		}
		if (queue->size >= 1) {
			topToken = queue->pick();
			while (!isOperation(topToken) && queue->size >= 2) {
				topToken = queue->pop();
				sign = queue->pop();
				varToken = calculate(topToken, sign, varToken);
				topToken = queue->pick();
			}
			queue->push(varToken);
			for (int i = 0; i < queue->size - 1; i++) {
				queue->push(queue->pop());
			}
		}
	}
	while (queue->size != 1) {
		varToken = queue->pop();
		topToken = queue->pop();
		sign = queue->pop();
		var = calculate(topToken, sign, varToken);
		queue->push(var);
		for (int i = 0; i < queue->size - 1; i++) {
			queue->push(queue->pop());
		}
	}
	return queue->pop();
}