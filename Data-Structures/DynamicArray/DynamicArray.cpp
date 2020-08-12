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
void DynamicArray<T>::push_back(T element)
{
	// check capacity
	if (size == capacity)
		resize(capacity * 2);

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
		resize(capacity * 2);

	// shift
	for (int i = size; i > index; i--)
		arr[i] = arr[i - 1];
	
	// add element
	arr[index] = element;
	size++;
}

template<typename T>
T DynamicArray<T>::at(int index)
{
	// check index 
	if (index < 0 || index >= size)
		throw "Index Out of Bounds";

	return arr[index];
}

template<typename T>
void DynamicArray<T>::clear()
{
	~DynamicArray();
	DynamicArray();
}

template<typename T>
bool DynamicArray<T>::isEmpty()
{
	return size == 0;
}

template<typename T>
T DynamicArray<T>::pop_back()
{
	// check emtiness
	if (size == 0)
		throw "Empty Array";

	// check capacity
	if (capacity > 4 * length)
		resize(capacity / 2);

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
		resize(capacity / 2);
	
	T temp = arr[index];
	// shift 
	for (int i = index; i < size - 1; i++)
		arr[i] = arr[i + 1];

	size--;
	return temp;
}

template<typename T>
void DynamicArray<T>::shrink()
{
	resize(size);
}

template<typename T>
void DynamicArray<T>::resize(int size)
{
	// same size
	if (mCapacity == size) return;

	capacity = size;
	T* arr = new T[capacity];

	// copy old
	for (int i = 0; i < size && i < this->size; i++)
		arr[i] = this->arr[i];

	if (size < this->size)
		this->size = size;

	delete[] this->arr;
	this->arr = arr;
}






