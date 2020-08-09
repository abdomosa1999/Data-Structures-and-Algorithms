#include "DynamicArray.h"



DynamicArray::DynamicArray()
{
	size = 0;
	capacity = 16;
	data = new int[capacity];
	for (int i = 0; i < capacity; i++)
		data[i] = 0;
}

DynamicArray::DynamicArray(int capacity)
{
	size = 0;
	this->capacity = capacity;
	data = new int[capacity];
	for (int i = 0; i < capacity; i++)
		data[i] = 0;
}


DynamicArray::~DynamicArray()
{
	delete[] data;
}

int DynamicArray::getSize()
{
	return size;
}

int DynamicArray::getCapacity()
{
	return capacity;
}

bool DynamicArray::add(int element)
{
	ensureCapacity(size);
	data[size++] = element;
	return true;
}

int DynamicArray::get(int index)
{
	if (index < 0 || index > capacity)
		return 0;
	return data[index];
}

bool DynamicArray::add(int element, int index)
{
	if (index < 0 || index > capacity)
		return false;
	data[index] = element;
	return true;
}

void DynamicArray::clear()
{
	size = 0;
}

bool DynamicArray::isEmpty()
{
	return (size == 0);
}

void DynamicArray::ensureCapacity(int capacity)
{
	if (capacity >= this->capacity) {
		int *temp = data;
		this->capacity *= 2;
		data = new int[this->capacity];
		for (int i = 0; i < capacity; i++)
			data[i] = temp[i];
		for (int i = capacity; i < this->capacity; i++)
			data[i] = 0;
		delete[] temp;
	}
}

void DynamicArray::print()
{
	std::cout << '{';
	for (int i = 0; i < capacity - 1; i++)
		std::cout << data[i] << ", ";
	std::cout << data[capacity - 1] << '}' << std::endl;
}

int DynamicArray::remove()
{
	int temp = data[--size];
	data[size] = 0;
	return temp;
}

int DynamicArray::remove(int index) // 1, 2, 4, 5
{
	int temp = data[index];
	size--;
	for (int i = index; i < size; i++)
		data[i] = data[i + 1];
	return temp;
}

void DynamicArray::shrink()
{
	if (size == capacity) return;
	capacity = size;
	int * temp = data;
	data = new int[capacity];
	for (int i = 0; i < capacity; i++)
		data[i] = temp[i];
	delete[] temp;
}
