#include "ListQueue.h"
// ����������� ������ ListQueue
ListQueue::ListQueue() {
	top = nullptr;
	bottom = nullptr;
	size = 0;
}

// ����� ������� �������� � ������� (������)
// �����������: �� ���� ��������� ����������� �������
// �����������: ��������� ������� � �������
void ListQueue::push(string value) {
	Node* node = new Node;
	node->data = value;
	node->next = nullptr;
	if (bottom != nullptr) {
		bottom->next = node;
	}
	if (top == nullptr) {
		top = node;
	}
	bottom = node;
	size++;
}

// ����� ������������ �������� �� ������� (������)
// �����������: ���������� �������� ������������ ��������
string ListQueue::pop() {
	string result;
	if (size > 1) {
		result = top->data;
		top = top->next;
		size--;
	}
	else if (size == 1) {
		result = top->data;
		size = 0;
		top = nullptr;
		bottom = nullptr;
	}
	else if (size == 0) {
		result = "";
		cout << "exeption" << endl;
	}
	return result;
}

// ����� ��������� �������� �������� � ������� ������� (������)
// �����������: ���������� �������� �������� � ������� �������
string ListQueue::pick() {
	if (size != 0) {
		return top->data;
	}
	else {
		return "";
	}
}

// ����� ������� ������� (������)
// �����������: ������� ��� �������� �� �������
void ListQueue::clear() {
	Node* nextNode;
	while (top != nullptr) {
		nextNode = top->next;
		delete top;
		top = nextNode;
	}
	size = 0;
	bottom = nullptr;
}

// ����� �������� ������� �� ������� (������)
// �����������: ���������� ��������, �����������, ����� �� �������
bool ListQueue::isEmpty() {
	return size == 0;
}