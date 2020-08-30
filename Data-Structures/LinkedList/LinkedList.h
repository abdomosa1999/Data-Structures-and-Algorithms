/* this is a double linked list class made by Abdo Mosa in c++ */

#pragma once
using namespace std;

template <typename T> class LinkedList;

// a class for the LinkedNode data type
template <typename T>
class LinkedNode {
	T data; 
	LinkedNode* next; 
	LinkedNode* previous;

	friend LinkedList<T>;
	
public:
	// a constructor to initialize fields
	LinkedNode(T element);
};


template <typename T>
class LinkedList
{
	LinkedNode<T>* head; // address of first node
	LinkedNode<T>* tail; // address of last node
	int size; // additional feild to decrease time complexity

	// private helpful methods to use
	LinkedNode<T> * iterateToIndex(int index);
	LinkedNode<T> * iterateToElement(T element);

public:
	LinkedList();
	~LinkedList();

	// capacity
	int getSize();
	bool isEmpty();

	// access
	T front();
	T back();
	T at(int index);

	// modify
	void insert(T element, int index);
	void pushFront(T element);
	void pushBack(T element);
	bool contains(T element);
	void update(int index, T element);
	void erase(T element);
	T popFront();
	T popBack();
	void clear();

	// operations
	void reverse();
	
};