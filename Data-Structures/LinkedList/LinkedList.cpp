#pragma once
#include "LinkedList.h"
#include <iostream>

template <typename T>
LinkedNode<T>::LinkedNode(T element) {
		data = element;
		next = nullptr;
		previous = nullptr;
}

template <typename T>
LinkedNode<T> * LinkedList<T>::iterateToIndex(int index)
{
	LinkedNode<T> * current;
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
LinkedNode<T> * LinkedList<T>::iterateToElement(T element)
{
	LinkedNode<T> * current;
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
	return iterateToIndex(index)->data;
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
		LinkedNode<T> * newLinkedNode = new LinkedNode<T>(element);
		LinkedNode<T> * current, *temp;
		current = iterateToIndex(index);
		temp = current->previous;
		current->previous = newLinkedNode;
		newLinkedNode->next = current;
		newLinkedNode->previous = temp;
		temp->next = newLinkedNode;
		size++;
	}
}

template<typename T>
void LinkedList<T>::pushFront(T element)
{
	LinkedNode<T>* newLinkedNode = new LinkedNode<T>(element);
	if (isEmpty()) {
		head = tail = newLinkedNode;
	}
	else {
		newLinkedNode->next = head;
		head->previous = newLinkedNode;
		head = newLinkedNode;
	}
	size++;
}

template<typename T>
void LinkedList<T>::pushBack(T element)
{
	LinkedNode<T>* newLinkedNode = new LinkedNode<T>(element);
	if (isEmpty()) {
		head = tail = newLinkedNode;
	}
	else {
		tail->next = newLinkedNode;
		newLinkedNode->previous = tail;
		tail = newLinkedNode;
	}
	size++;
}

template<typename T>
bool LinkedList<T>::contains(T element)
{
	return iterateToElement(element) != nullptr;
}

template<typename T>
void LinkedList<T>::erase(T element)
{
	LinkedNode<T> * current = iterateToElement(element);
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

	LinkedNode<T> * current = head;
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

	LinkedNode<T> * current = tail;
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

	LinkedNode<T> * current = iterateToIndex(index);
	current->data = element; // update the value
}

template<typename T>
void LinkedList<T>::reverse()
{
	LinkedNode<T> * current = head, *temp;
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
	LinkedNode<T> * current = head;
	LinkedNode<T> * temp;
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
