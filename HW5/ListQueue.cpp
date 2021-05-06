#include "ListQueue.h"
// Конструктор класса ListQueue
ListQueue::ListQueue() {
	top = nullptr;
	bottom = nullptr;
	size = 0;
}

// Метод вставки элемента в очередь (список)
// Предусловие: на вход поступает вставляемый элемент
// Постусловие: вставляет элемент в очередь
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

// Метод выталкивания элемента из очереди (список)
// Постусловие: возвращает значение вытолкнутого элемента
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

// Метод получения значения элемента в вершине очереди (список)
// Постусловие: возвращает значение элемента в вершине очереди
string ListQueue::pick() {
	if (size != 0) {
		return top->data;
	}
	else {
		return "";
	}
}

// Метод очистки очереди (список)
// Постусловие: удаляет все элементы из очереди
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

// Метод проверки очереди на пустоту (список)
// Постусловие: возвращает значение, описывающее, пуста ли очередь
bool ListQueue::isEmpty() {
	return size == 0;
}