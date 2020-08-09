#include "LinkedList.h"
#include <iostream>

/*LinkedList::LinkedList()
{
	size = 0;
	head = 0;
}

LinkedList::~LinkedList()
{
}

void LinkedList::add(int element)
{
	Node *last = new Node(element), *p = head;
	while (p->next != head)
		p = p->next;
	p->next = last;
	size++;
}

void LinkedList::add(int element, int index)
{
	Node *n = new Node(element), *p = head;
	for (int i = 1; i < index - 1; i++)
		p = p->next;
	n->next = p->next;
	p->next = n;
	size++;
}

int LinkedList::get()
{
	if (isEmpty()) return 0;
	Node *p = head;
	while (p->next != head)
		p = p->next;
	return p->data;
}

int LinkedList::get(int index)
{
	if (index < 1 || index > size) return 0;
	Node *p = head;
	for (int i = 1; i < index; i++)
		p = p->next;
	return p->data;
}

int LinkedList::getHead()
{
	return isEmpty() ? 0 : head->data;
}

int LinkedList::getSize()
{
	return size;
}

int LinkedList::remove()
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

int LinkedList::remove(int index)
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

void LinkedList::clear()
{
	head = 0;
	size = 0;
}

void LinkedList::print()
{
	if (isEmpty()) return;
	Node *temp = head;
	for (int i = 0; i < size; i++) {
		std::cout << temp->data;
		temp = temp->next;
	}
	std::cout << std::endl;
}

bool LinkedList::isEmpty()
{
	return (head == 0);
}
*/