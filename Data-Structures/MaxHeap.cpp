#pragma once
#include <iostream>
using namespace std;
template <typename T>
class MaxHeap
{
	T * heap;
	int size, maxSize;

	int parent(int pos)
	{
		return pos / 2;
	}

	int left(int pos)
	{
		return pos * 2;
	}
	int right(int pos)
	{
		return pos * 2 + 1;
	}
	bool isLeaf(int pos) 
	{
		return (pos >= (size / 2.0) && pos <= size);
	}

	void swap(int f, int s) {
		T temp = heap[f];
		heap[f] = heap[s];
		heap[s] = temp;
	}
	void heapify(int pos) {
		if (isLeaf(pos)) return;
		if (heap[pos] > heap[left(pos)] && heap[pos] > heap[right(pos)]) return;
		if (heap[left(pos)] > heap[right(pos)]) {
			swap(pos, left(pos));
			heapify(left(pos));
		}
		else {
			swap(pos, right(pos));
			heapify(right(pos));
		}
	}
public:
	MaxHeap() {
		maxSize = 16;
		size = 0;
		heap = new T[maxSize + 1] { 0 };
	}
	MaxHeap(int maxSize) {
		this->maxSize = maxSize;
		size = 0;
		heap = new T[maxSize + 1]{ 0 };
	}
	~MaxHeap() {
		delete[] heap;
	}

	int getMax() {
		return heap[1];
	}

	void push(T element) {
		if (size >= maxSize) return;

		heap[++size] = element;

		for (int temp = size; heap[temp] > heap[parent(temp)] && parent(temp) > 0; temp = parent(temp))
			swap(temp, parent(temp));
	}
	void print() {
		for (int i = 1; i <= size / 2; i++)
			cout << " PARENT : " << heap[i]
			<< " LEFT CHILD : " << heap[left(i)]
			<< " RIGHT CHILD :" << heap[right(i)]
			<< endl;
	}
	T pop() {
		T popped = heap[1];
		heap[1] = heap[size];
		heapify(1);
		return popped;
	}
};

int llmain() {
	MaxHeap<int>* myMaxHeap = new MaxHeap<int>();
	myMaxHeap->push(5);
	myMaxHeap->push(9);
	myMaxHeap->push(1);
	myMaxHeap->push(8);
	myMaxHeap->push(2);
	myMaxHeap->print();
	cout << "First Pop: " << myMaxHeap->pop() << endl;
	cout << "Second Pop: " << myMaxHeap->pop() << endl;
	myMaxHeap->print();
	return 0;
}