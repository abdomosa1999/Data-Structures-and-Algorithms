#pragma once

template <typename T> class Queue;

template <typename T>
class QueueNode {
	T data;
	QueueNode<T> * next, * prev;

	friend Queue<T>;
public:
	QueueNode(T element);
};

template <typename T>
class Queue {
	QueueNode<T> * head, * tail;
	int size;
public:
	Queue();
	~Queue();

	bool isEmpty();
	int getSize();
	T front();
	T back();

	void enqueue(T element);
	T dequeue();
	void print();
};