#include "CircularLinkedList.h"
#include <iostream>



CircularLinkedList::CircularLinkedList()
{
	size = 0;
	head = 0;
}

CircularLinkedList::~CircularLinkedList()
{
}

void CircularLinkedList::add(int element)
{
	if (size == 0) {
		head = new Node(element);
		head->next = head;
	}
	else {
		Node *last = new Node(element), *p = head;
		while (p->next != head)
				p = p->next;
		p->next = last;
		last->next = head;
	}
	size++;
}

void CircularLinkedList::add(int element, int index)
{
	Node *n = new Node(element), *p = head;
	for (int i = 1;i < index - 1; i++)
		p = p->next;
	n->next = p->next;
	p->next = n;
	size++;
}

int CircularLinkedList::get()
{
	if (isEmpty()) return 0;
	Node *p = head;
	while (p->next != head)
		p = p->next;
	return p->data;
}

int CircularLinkedList::get(int index)
{
	if (index < 1 || index > size) return 0;
	Node *p = head;
	for (int i = 1; i < index; i++)
		p = p->next;
	return p->data;
}

int CircularLinkedList::getHead()
{
	return isEmpty()? 0 : head->data;
}

int CircularLinkedList::getSize()
{
	return size;
}

int CircularLinkedList::remove()
{
	if (isEmpty()) return 0;
	Node *p = head;
	while (p->next != head)
		p = p->next;
	int temp = p->data;
	p->next = p->next->next;
	size--;
	return temp;
}

int CircularLinkedList::remove(int index)
{
	if (index < 1 || index > size) return 0;
	Node *p = head;
	for (int i = 1; i < index - 1; i++)
		p = p->next;
	int temp = p->next->data;
	p->next = p->next->next;
	size--;
	return temp;
}

void CircularLinkedList::clear()
{
	head = 0;
	size = 0;
}

void CircularLinkedList::print()
{
	if (isEmpty()) return;
	Node *temp = head;
	for (int i = 0; i < size; i++) {
		std::cout << temp->data;
		temp = temp->next;
	}
	std::cout << std::endl;
}

bool CircularLinkedList::isEmpty()
{
	return (head == 0);
}