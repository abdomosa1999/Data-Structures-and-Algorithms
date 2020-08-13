#pragma once
#include "DynamicArray.h"

template <typename T>
DynamicArray<T>::DynamicArray() {
	size = 0;
	capacity = 16; // default size 16 element
	arr = new T[capacity];
}

template <typename T>
DynamicArray<T>::DynamicArray(int capacity) {
	size = 0;
	this.capacity = capacity;
	arr = new T[capacity];
}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& arr) {
	
}

template <typename T>
DynamicArray<T>::~DynamicArray() {
	delete[] arr;
}

template<typename T>
int DynamicArray<T>::getSize()
{
	return size;
}

template<typename T>
int DynamicArray<T>::getCapacity()
{
	return capacity;
}

template<typename T>
bool DynamicArray<T>::isEmpty()
{
	return size == 0;
}

template<typename T>
void DynamicArray<T>::reserve(int capacity)
{
	// same size
	if (this->capacity == capacity) return;

	this->capacity = capacity;
	T* arr = new T[capacity];

	// copy old
	for (int i = 0; i < capacity && i < this->size; i++)
		arr[i] = this->arr[i];

	if (capacity < this->size)
		this->size = capacity;

	delete[] this->arr;
	this->arr = arr;
}

template<typename T>
void DynamicArray<T>::shrink()
{
	reserve(size);
}

template<typename T>
void DynamicArray<T>::push_back(T element)
{
	// check capacity
	if (size == capacity)
		reserve(capacity * 2);

	// add element
	arr[size++] = element;
}

template<typename T>
void DynamicArray<T>::insert(T element, int index)
{
	// check index 
	if (index < 0 || index > size)
		throw "Index Out of Bounds";

	// check capacity
	if (size == capacity)
		reserve(capacity * 2);

	// shift
	for (int i = size; i > index; i--)
		arr[i] = arr[i - 1];
	
	// add element
	arr[index] = element;
	size++;
}

template<typename T>
T & DynamicArray<T>::operator[](int index)
{
	return at(index);
}

template<typename T>
T & DynamicArray<T>::at(int index)
{
	// check index 
	if (index < 0 || index >= size)
		throw "Index Out of Bounds";

	return arr[index];
}

template<typename T>
T DynamicArray<T>::front()
{
	// check emptiness
	if (size == 0)
		throw "Empty List";

	return arr[0];
}

template<typename T>
T DynamicArray<T>::back()
{
	// check emptiness
	if (size == 0)
		throw "Empty List";

	return arr[size - 1];
}

template<typename T>
void DynamicArray<T>::clear()
{
	~DynamicArray();
	DynamicArray();
}

template<typename T>
T DynamicArray<T>::pop_back()
{
	// check emtiness
	if (size == 0)
		throw "Empty Array";

	// check capacity
	if (capacity > 4 * size)
		reserve(capacity / 2);

	return arr[--size];
}

template<typename T>
T DynamicArray<T>::erase(int index)
{
	// check index
	if (index < 0 || index >= size)
		throw "Index Out of Bounds";

	// check capacity
	if (capacity > 4 * size)
		reserve(capacity / 2);
	
	T temp = arr[index];
	// shift 
	for (int i = index; i < size - 1; i++)
		arr[i] = arr[i + 1];

	size--;
	return temp;
}


// overload the operator << to work with this object
template<class T>
std::ostream & operator<<(std::ostream & out, DynamicArray<T>& x) {
	out << "{";
	for (int i = 0; i < x.getSize() - 1; i++) {
		out << x[i] << ", ";
	}
	out << x[x.getSize() - 1] << "}";
	return out;
}
