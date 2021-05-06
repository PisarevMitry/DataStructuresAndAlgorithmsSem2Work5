#include "ArrayQueue.h"

// ����������� ������ ArrayQueue
ArrayQueue::ArrayQueue(int n) {
	array = new string[n];
	size = 0;
	max_size = n;
}

// ����� ������� �������� � ������� (������)
// �����������: �� ���� ��������� ����������� �������
// �����������: ��������� ������� � �������
void ArrayQueue::push(string value) {
	array[size] = value;
	size++;
}

// ����� ������������ �������� �� ������� (������)
// �����������: ���������� �������� ������������ ��������
string ArrayQueue::pop() {
	string result = array[0];
	for (int i = 0; i < size - 1; i++)
		array[i] = array[i + 1];
	size--;
	return result;
}

// ����� ��������� �������� �������� � ������� ������� (������)
// �����������: ���������� �������� �������� � ������� �������
string ArrayQueue::pick() {
	return array[0];
}

// ����� ������� ������� (������)
// �����������: ������� ��� �������� �� �������
void ArrayQueue::clear() {
	delete[] array;
	array = new string[max_size];
	size = 0;
}

// ����� �������� ������� �� ������� (������)
// �����������: ���������� ��������, �����������, ����� �� �������
bool ArrayQueue::isEmpty() {
	return size == 0;
}