#include "Queue.h"
#include <iostream>
using namespace std;

template <typename T>
QueueNode<T>::QueueNode(T element) {
	data = element;
	next = prev = NULL;
}

template <typename T>
Queue<T>::Queue() {
	head = tail = NULL;
	size = 0;
}

template <typename T>
Queue<T>::~Queue() {
	QueueNode<T> * it = head;
	while (it != NULL)
	{
		QueueNode<T> * temp = it;
		it = it->next;
		delete temp;
	}
}

template<typename T>
bool Queue<T>::isEmpty()
{
	return (size == 0);
}

template<typename T>
int Queue<T>::getSize()
{
	return size;
}

template<typename T>
T Queue<T>::front()
{
	if (isEmpty())
		throw "Empty Queue";
	return head->data;
}

template<typename T>
T Queue<T>::back()
{
	if (isEmpty())
		throw "Empty Queue";
	return tail->data;
}

template <typename T>
void Queue<T>::enqueue(T element) {
	QueueNode<T> * newNode = new QueueNode<T>(element);
	newNode->next = head;
	if (head != NULL)
		head->prev = newNode;
	else
		tail = newNode;
	head = newNode;
	size++;
}

template <typename T>
T Queue<T>::dequeue()
{
	if (isEmpty())
		throw "Empty Queue!";
	QueueNode<T> * temp = tail;
	T element = tail->data;
	tail = tail->prev;
	tail->next = NULL;
	delete temp;
	size--;
	return element;
}

template <typename T>
void Queue<T>::print()
{
	QueueNode<T> * it = head;
	while (it != NULL)
	{
		cout << it->data << ", ";
		it = it->next;
	}
	cout << endl;
}
