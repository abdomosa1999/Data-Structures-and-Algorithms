#pragma once
template <typename T> class BinaryTree;

template <typename T>
class BinaryNode {
	T data;
	BinaryNode<T> * left, * right;

	friend BinaryTree<T>;
public:
	BinaryNode(T element);
};

template <typename T>
class BinaryTree {
	BinaryNode<T> * root;

	BinaryNode<T> * levelOrderTraversal();
	BinaryNode<T> * traverseLevel(BinaryNode<T> * start, int level);
	int _height(BinaryNode<T> * node);
	// BinaryNode<T> * iterate(T element);
public:
	BinaryTree();
	~BinaryTree();
	// int getSize();
	// bool isEmpty();
	void insert(T element);
	// void insert(T element, T after);
	// bool search(T element);
	// void clear();
	// void remove(T element);
	// void print();
	int height();
};
