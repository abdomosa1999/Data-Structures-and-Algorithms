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
	int getSize();
	void push_back(T element);
	void insert(T element, int index);
	T at(int index);
	void clear();
	bool isEmpty();
	T pop_back();
	T erase(int index);
	void shrink();
	void resize(int size);
};
