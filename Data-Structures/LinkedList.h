#pragma once
#include <iostream>
using namespace std;

/* this is a double linked list class made by Abdo Mosa in c++ */
template <typename T>
class LinkedList
{
	// a class for the Node data type
	class Node {
	public:
		T key; // contains the data value
		Node* next; // contains a link to the next node
		Node* previous; // contains a link to the previous node

		// a constructor to initialize fields
		Node(T element) {
			key = element;
			next = NULL;
			previous = NULL;
		}
	};

	// class data members 
	Node* head; // contains the address of the first node of the linked list
	Node* tail; // contains the address of the last node of the linked list
	int size; // additional feild to store up the size and decrease time complexity

	/* private iterate methods to help with coding, 
	the methods iterate over the nodes and find the specific node we're looking for,
	the search is either by index or the data itself then return it as a node */
	Node* iterate(int index) {
		Node* current;
		// choose which end to iterate from to reduce complexity
		if (index < size / 2) {
			current = head;
			for (int i = 0; i < index; current = current->next, i++);
		}
		else {
			current = tail;
			for (int i = size - 1; i > index; current = current->previous, i--);
		}
		return current;
	}

	Node* iterate(T element) {
		Node* current;
		current = head;
		for (int i = 0; i < size; current = current->next, i++)
			if (current->key == element)
				return current;
		return NULL;
	}
public:
	// a zero-arguement constructor to initialize data members
	LinkedList() {
		head = NULL;
		tail = NULL;
		size = 0;
	}

	// a destructor that frees up the memory
	~LinkedList() {
		clear();
	}

	// get the size
	int getSize() {
		return size;
	}

	// return the first element if exists
	T first() {
		return (head == NULL) ? NULL : head->key;
	}

	// return the last element if exists
	T last() {
		return (tail == NULL) ? NULL : tail->key;
	}

	// return the element at a specific index with the use of the iterate function
	T at(int index) {
		if (index < 0 || index >= size) return NULL;
		return iterate(index)->key;
	}

	// add an element at a specific index
	bool insert(int index, T element) {
		// check the index validation
		if (index < 0 || index > size) return false;

		// create the new node
		Node* newNode = new Node(element);

		// if it's empty there's no need to traverse
		if (isEmpty()) {
			head = tail = newNode;
		}
		// if it's the first element there's specific actions to take (no previous node)
		else if (index == 0) {
			newNode->next = head;
			head->previous = newNode;
			head = newNode;
		}
		// if it's the last element there's specific actions to take(no next node)
		else if (index == size) {
			tail->next = newNode;
			newNode->previous = tail;
			tail = newNode;
		}
		// other than that, traverse and insert the element in the right position
		else {
			Node* current, *temp;
			current = iterate(index);
			temp = current->previous;
			current->previous = newNode;
			newNode->next = current;
			newNode->previous = temp;
			temp->next = newNode;
		}
		// increase size by one and mark as done
		size++;
		return true;
	}

	// add an element at the first with the use of insert method
	void addFirst(T element) {
		insert(0, element);
	}

	// add an element at the last with the use of insert method
	void addLast(T element) {
		insert(size, element);
	}

	// get the index of an element if it's found and -1 otherwise
	int indexOf(T element) {
		Node* current = head;
		for (int i = 0; i < size; current = current->next, i++)
			if (current->key == element)
				return i;
		return -1;
	}

	// check if a soecific element exists with the use of indexOf method
	bool contains(T element) {
		return (indexOf(element) != -1);
	}

	// delete a specific element
	bool remove(T element) {
		Node* current = iterate(element);
		if (current == NULL) return false; // it's not there already
		current->previous->next = current->next;
		current->next->previous = current->previous;
		// free up from memory, decrease size and mark as done
		delete current;
		size--;
		return true;
	}

	// delete the first element
	void removeFirst() {
		if (isEmpty()) return;

		Node* current = head;
		if (size == 1) {
			head = tail = NULL;
		}
		else {
			head = current->next;
			head->previous = NULL;
		}
		delete current;
		size--;
	}

	// delete the last element
	void removeLast() {
		if (isEmpty()) return;

		Node* current = tail;
		if (size == 1) {
			head = tail = NULL;
		}
		else {
			tail = current->previous;
			tail->next = NULL;
		}
		delete current;
		size--;
	}

	// modify a soecific node with a new element/key
	bool update(int index, T element) {
		// check index validation
		if (index < 0 || index >= size) return false;

		Node* current = iterate(index);
		current->key = element; // update the value
		return true;
	}

	// reverse the whole linked list
	void reverse() {
		Node* current = head, *temp;
		head = tail;
		tail = current;
		// traverse from the begining and swap every next and previous
		for (int i = 0; i < size; i++) {
			temp = current->next;
			current->next = current->previous;
			current->previous = temp;
			current = current->previous;
		}
	}

	// a method that delete the whole linked list nodes
	void clear() {
		Node* current = head;
		Node* temp;
		for (int i = 0; i < size; i++) {
			temp = current->next;
			delete current;
			current = temp;
		}
		size = 0;
	}

	// check if the list is empty or not
	bool isEmpty() {
		return (size == 0);
	}

	// a method that displays the whole list to the console
	void print() {
		Node* current = head;
		cout << endl;
		for (int i = 0; i < size; i++) {
			cout << current->key;
			if (i != size - 1)
				cout << ", ";
			current = current->next;
		}
		cout << endl;
	}
};