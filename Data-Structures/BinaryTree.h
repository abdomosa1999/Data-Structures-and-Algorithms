#pragma once

template <typename T>
class BinaryTree {
	class Node;
	Node* root;
public:
	BinaryTree();
	int size();
	void insert(T element);
	void insert(T element, T after);
	bool search(T element);
	void clear();
	void sort();
	void remove(T element);
	void print();
	int maxDepth();
	void mirror();
};


