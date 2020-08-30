#pragma once
#include "Stack.h"
#include <iostream>
using namespace std;

template <typename T>
StackNode<T>::StackNode(T element) {
	data = element;
	next = NULL;
}


template <typename T>
Stack<T>::Stack() {
	head = NULL;
}

template <typename T>
Stack<T>::~Stack() {
	StackNode<T> * it = head;
	while (it != NULL)
	{
		StackNode<T> * temp = it;
		it = it->next;
		delete temp;
	}
}

template<typename T>
int Stack<T>::getSize()
{
	return size;
}

template<typename T>
bool Stack<T>::isEmpty()
{
	return (size == 0);
}

template <typename T>
void Stack<T>::push(T element) {
	StackNode<T> * newNode = new StackNode<T>(element);
	newNode->next = head;
	head = newNode;
	size++;
}

template <typename T>
T Stack<T>::pop()
{
	if (head == NULL)
		throw "Empty Stack!";

	StackNode<T> * temp = head;
	T element = head->data;
	head = head->next;
	delete temp;
	size--;
	return element;
}

template <typename T>
T Stack<T>::top()
{
	if (head == NULL)
		throw "Empty Stack!";
	return head->data;
}

template <typename T>
void Stack<T>::print()
{
	StackNode<T> * it = head;
	while (it != NULL)
	{
		cout << it->data << ", ";
		it = it->next;
	}
	cout << endl;
}
