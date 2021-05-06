#include "ArrayQueue.h"

// Конструктор класса ArrayQueue
ArrayQueue::ArrayQueue(int n) {
	array = new string[n];
	size = 0;
	max_size = n;
}

// Метод вставки элемента в очереди (массив)
// Предусловие: на вход поступает вставляемый элемент
// Постусловие: вставляет элемент в очередь
void ArrayQueue::push(string value) {
	array[size] = value;
	size++;
}

// Метод выталкивания элемента из очереди (массив)
// Постусловие: возвращает значение вытолкнутого элемента
string ArrayQueue::pop() {
	string result = array[0];
	for (int i = 0; i < size - 1; i++)
		array[i] = array[i + 1];
	size--;
	return result;
}

// Метод получения значения элемента в вершине очереди (массив)
// Постусловие: возвращает значение элемента в вершине очереди
string ArrayQueue::pick() {
	return array[0];
}

// Метод очистки очереди (массив)
// Постусловие: удаляет все элементы из очереди
void ArrayQueue::clear() {
	delete[] array;
	array = new string[max_size];
	size = 0;
}

// Метод проверки очереди на пустоту (массив)
// Постусловие: возвращает значение, описывающее, пуста ли очередь
bool ArrayQueue::isEmpty() {
	return size == 0;
}