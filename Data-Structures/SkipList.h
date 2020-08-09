#pragma once
#include <iostream>
#include <ctime>
using namespace std;

class SkipList
{
	class Node {
	public:
		int data;
		Node *right, *left, *up, *down;

		Node(int element) {
			data = element;
			right = left = up = down = NULL;
		}
	};
	Node* head, *tail;
	int height, size;

	Node* iterate(int element);
public:
	SkipList();
	~SkipList();

	void insert(int element);
	bool search(int element);
	bool remove(int element);
	void clear();
	int getSize();
	void print();
};