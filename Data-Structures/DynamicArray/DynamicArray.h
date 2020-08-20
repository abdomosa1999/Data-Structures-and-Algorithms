/* This is a generic class implementing the dynamic array
	data structure in c++ made by: Abdo Mosa*/

#pragma once
#include <iostream>

template <typename T>
class DynamicArray
{
	int size, capacity;
	T *arr;
public:
	DynamicArray(); // default constructor
	DynamicArray(int capacity); // sized constructor
	DynamicArray(const DynamicArray<T>& arr); // copy constructor
	~DynamicArray();

	// capacity
	int getSize();
	int getCapacity();
	bool isEmpty();
	void reserve(int capacity);
	void shrink();

	// access
	T & operator[](int index);
	T & at(int index);
	T front();
	T back();

	// modify
	// =
	void pushBack(T element);
	void insert(T element, int index);
	T popBack();
	T erase(int index);
	void clear();
	
};

