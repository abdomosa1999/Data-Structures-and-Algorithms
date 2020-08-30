#pragma once
template <typename T> class BinaryTree;

template <typename T>
class Node {

};

template <typename T>
class BinaryTree {
	Node<T> * root;
public:
	BinaryTree();
	~BinaryTree();
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


