#pragma once
class CircularLinkedList
{
	class Node {
	public:
		int data;
		Node *next;

		Node() : data(0), next(0) {}
		Node(int element) {
			data = element;
			next = 0;
		}
	};
	Node *head;
	int size;
public:
	CircularLinkedList();
	~CircularLinkedList();
	void add(int element);
	void add(int element, int index);
	int get();
	int get(int index);
	int getHead();
	int getSize();
	int remove();
	int remove(int index);
	void clear();
	void print();
	bool isEmpty();
};