#include <iostream>
using namespace std;

template <typename T>
class Stack {
	class Node {
	public:
		T data;
		Node* next;
		Node(T element) {
			data = element;
			next = NULL;
		}
	};

	Node* head;

public:
	Stack() {
		head = NULL;
	}

	~Stack() {
		Node* it = head;
		while (it != NULL)
		{
			Node* temp = it;
			it = it->next;
			delete temp;
		}
	}

	void push(T element) {
		Node* newNode = new Node(element);
		newNode->next = head;
		head = newNode;
	}

	T pop() 
	{
		if (head == NULL)
			throw "Empty Stack!";
		Node* temp = head;
		T element = head->data;
		head = head->next;
		delete temp;
		return element;
	}

	T peak() 
	{
		if (head == NULL)
			throw "Empty Stack!";
		return head->data;
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