#include <iostream>
using namespace std;

template <typename T>
class Queue {
	class Node {
	public:
		T data;
		Node *next, *prev;
		Node(T element) {
			data = element;
			next = prev = NULL;
		}
	};

	Node *head, *tail;

public:
	Queue() {
		head = tail = NULL;
	}

	~Queue() {
		Node* it = head;
		while (it != NULL)
		{
			Node* temp = it;
			it = it->next;
			delete temp;
		}
	}

	void enqueue(T element) {
		Node* newNode = new Node(element);
		newNode->next = head;
		if (head != NULL)
			head->prev = newNode;
		else
			tail = newNode;
		head = newNode;
	}

	T dequeue()
	{
		if (head == NULL)
			throw "Empty Stack!";
		Node* temp = tail;
		T element = tail->data;
		tail = tail->prev;
		tail->next = NULL;
		delete temp;
		return element;
	}

	void print()
	{
		Node* it = head;
		while (it != NULL)
		{
			cout << it->data << ", ";
			it = it->next;
		}
		cout << endl;
	}
};
