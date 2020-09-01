#include "BinaryTree.h"

template <typename T>
BinaryNode<T>::BinaryNode(T element) {
	data = element;
	left = right = nullptr;
}

template<typename T>
BinaryNode<T> * BinaryTree<T>::levelOrderTraversal()
{
	int h = height();
	for (int i = 1; i <= h; i++) {
		BinaryNode<T> * node = traverseLevel(root, i);
		if (node != nullptr)
			return node;
	}
	return root;
}

template<typename T>
BinaryNode<T> * BinaryTree<T>::traverseLevel(BinaryNode<T> * start, int level)
{
	if (level < 1)
		return nullptr;

	if (level == 1 && (start->left == nullptr || start->right == nullptr))
		return start;

	BinaryNode<T> * node = traverseLevel(start->left, level - 1);
	if (node != nullptr)
		return node;
	return traverseLevel(start->right, level - 1);
}

template<typename T>
int BinaryTree<T>::_height(BinaryNode<T>* node)
{
	if (node == nullptr)
		return 0;

	int lheight = _height(node->left);
	int rheight = _height(node->right);

	if (lheight > rheight)
		return lheight + 1;
	else
		return rheight + 1;
}

template <typename T>
BinaryTree<T>::BinaryTree() {
	root = nullptr;
}

template<typename T>
BinaryTree<T>::~BinaryTree()
{

}

/* template<typename T>
int BinaryTree<T>::getSize()
{
	return size;
}

template<typename T>
bool BinaryTree<T>::isEmpty()
{
	return (size == 0);
}
*/ 
template<typename T>
void BinaryTree<T>::insert(T element)
{
	BinaryNode<T> * newNode = new BinaryNode<T>(element);
	
	if (root == nullptr) {
		root = newNode;
		return;
	}

	BinaryNode<T> * node = levelOrderTraversal();
	if (node->left == nullptr)
		node->left = newNode;
	else
		node->right = newNode;
}

template<typename T>
int BinaryTree<T>::height()
{
	return _height(root);
}
