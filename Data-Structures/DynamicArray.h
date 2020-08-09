#pragma once
#include <iostream>

class DynamicArray
{
	int size, capacity;
	int *data;
public:
	DynamicArray();
	DynamicArray(int capacity);
	~DynamicArray();
	int getSize();
	int getCapacity();
	bool add(int element);
	bool add(int element, int index);
	int get(int index);
	void clear();
	bool isEmpty();
	void print();
	int remove();
	int remove(int index);
	void shrink();
private:
	void ensureCapacity(int capacity);
};