#pragma once
template <typename T> class Stack;

template <typename T>
class StackNode {
	T data;
	StackNode * next;

	friend Stack<T>;
public:
	StackNode(T element);
};


template <typename T>
class Stack {
	StackNode<T> * head;
	int size;

public:
	Stack();
	~Stack();

	// capacity
	int getSize();
	bool isEmpty();

	// access
	T top();
	void print();

	// modify
	void push(T element);
	T pop();
};