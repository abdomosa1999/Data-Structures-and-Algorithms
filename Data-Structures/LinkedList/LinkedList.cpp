#include "LinkedList.h"
#include <iostream>

template <typename T>
Node<T>::Node(T element) {
		data = element;
		next = nullptr;
		previous = nullptr;
}

template <typename T>
Node<T> * LinkedList<T>::iterate(int index)
{
	Node<T> * current;
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

template<typename T>
Node<T> * LinkedList<T>::iterate(T element)
{
	Node<T> * current;
	current = head;
	for (int i = 0; i < size; current = current->next, i++)
		if (current->data == element)
			return current;
	return nullptr;
}

template<typename T>
LinkedList<T>::LinkedList()
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}

template<typename T>
LinkedList<T>::~LinkedList()
{
	clear();
}

template<typename T>
int LinkedList<T>::getSize()
{
	return size;
}

template<typename T>
T LinkedList<T>::front()
{	
	if (isEmpty())
		throw "Empty List";
	return head->data;
}

template<typename T>
T LinkedList<T>::back()
{
	if (isEmpty())
		throw "Empty List";
	return tail->data;
}

template<typename T>
T LinkedList<T>::at(int index)
{
	if (index < 0 || index >= size)
		throw "Index Out of Bounds";
	return iterate(index)->data;
}

template<typename T>
void LinkedList<T>::insert(T element, int index)
{
	// check the index validation
	if (index < 0 || index > size) 
		throw "Index Out of Bounds";

	if (index == 0 || isEmpty()) {
		pushFront(element);
	}

	else if (index == size) {
		pushBack(element);
	}

	else {
		Node<T> * newNode = new Node<T>(element);
		Node<T> * current, *temp;
		current = iterate(index);
		temp = current->previous;
		current->previous = newNode;
		newNode->next = current;
		newNode->previous = temp;
		temp->next = newNode;
		size++;
	}
}

template<typename T>
void LinkedList<T>::pushFront(T element)
{
	Node<T>* newNode = new Node<T>(element);
	if (isEmpty()) {
		head = tail = newNode;
	}
	else {
		newNode->next = head;
		head->previous = newNode;
		head = newNode;
	}
	size++;
}

template<typename T>
void LinkedList<T>::pushBack(T element)
{
	Node<T>* newNode = new Node<T>(element);
	if (isEmpty()) {
		head = tail = newNode;
	}
	else {
		tail->next = newNode;
		newNode->previous = tail;
		tail = newNode;
	}
	size++;
}

template<typename T>
bool LinkedList<T>::contains(T element)
{
	return iterate(element) != nullptr;
}

template<typename T>
void LinkedList<T>::erase(T element)
{
	Node<T> * current = iterate(element);
	if (current == nullptr)
		return;

	if (current == head) {
		popFront();
	}

	else if (current == tail) {
		popBack();
	}
	else {
		current->previous->next = current->next;
		current->next->previous = current->previous;
		delete current;
		size--;
	}
}

template<typename T>
T LinkedList<T>::popFront()
{
	if (isEmpty()) 
		throw "Empty List";

	Node<T> * current = head;
	if (size == 1) {
		head = tail = nullptr;
	}
	else {
		head = current->next;
		head->previous = nullptr;
	}
	T temp = current->data;
	delete current;
	size--;
	return temp;
}

template<typename T>
T LinkedList<T>::popBack()
{
	if (isEmpty()) 
		throw "Empty List";

	Node<T> * current = tail;
	if (size == 1) {
		head = tail = nullptr;
	}
	else {
		tail = current->previous;
		tail->next = nullptr;
	}
	T temp = current->data;
	delete current;
	size--;
	return temp;
}

template<typename T>
void LinkedList<T>::update(int index, T element)
{
	// check index validation
	if (index < 0 || index >= size)
		throw "Index Out of Bounds";

	Node<T> * current = iterate(index);
	current->data = element; // update the value
}

template<typename T>
void LinkedList<T>::reverse()
{
	Node<T> * current = head, *temp;
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

template<typename T>
void LinkedList<T>::clear()
{
	Node<T> * current = head;
	Node<T> * temp;
	for (int i = 0; i < size; i++) {
		temp = current->next;
		delete current;
		current = temp;
	}
	size = 0;
}

template<typename T>
bool LinkedList<T>::isEmpty()
{
	return (size == 0);
}

// overload the operator << to work with this object
template<class T>
std::ostream & operator<<(std::ostream & out, LinkedList<T>& x) {
	out << "{";
	for (int i = 0; i < x.getSize() - 1; i++) {
		out << x.at(i) << ", ";
	}
	out << x.at(x.getSize() - 1) << "}";
	return out;
}
