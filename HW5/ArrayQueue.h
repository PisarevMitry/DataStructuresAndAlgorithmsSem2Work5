#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

#include <iostream>
#include <string>

using namespace std;

class ArrayQueue {
public:
	string* array;
	int max_size;
	int size;

public:
	ArrayQueue(int n);
	string pop();
	void push(string value);
	string pick();
	void clear();
	bool isEmpty();
};

#endif