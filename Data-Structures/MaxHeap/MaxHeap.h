#pragma once
#include <iostream>
using namespace std;
class MaxHeap
{
	int * heap;
	int size, maxSize;

	int parent(int pos);
	int left(int pos);
	int right(int pos);
	bool isLeaf(int pos);
	void swap(int f, int s);
	void heapify(int pos);
public:
	MaxHeap();
	MaxHeap(int maxSize);
	~MaxHeap();
	void insert(int element);
	void print();
	int remove();
};

