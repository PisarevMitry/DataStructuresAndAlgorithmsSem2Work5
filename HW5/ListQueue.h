#ifndef LISTQUEUE_H
#define LISTQUEUE_H

#include <iostream>
#include <string>

using namespace std;

struct Node {
	string data;
	Node* next;
};

class ListQueue {
public:
	Node* top;
	Node* bottom;
	int size;

public:
	ListQueue();
	string pop();
	void push(string value);
	string pick();
	void clear();
	bool isEmpty();
};

#endif 