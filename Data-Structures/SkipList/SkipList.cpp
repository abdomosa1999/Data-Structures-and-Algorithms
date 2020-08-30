#pragma once
#include "SkipList.h"

SkipNode::SkipNode(int element) {
	data = element;
	right = left = up = down = NULL;
}


SkipNode * SkipList::iterate(int element)
{
	SkipNode* current = head;
	while (true) {
		while (current->right->data != INT_MAX && current->right->data <= element)
			current = current->right;
		if (current->down != NULL)
			current = current->down;
		else
			break;
	}
	return current;
}

SkipList::SkipList()
{
	SkipNode* nInfinity = new SkipNode(INT_MIN), *pInfinity = new SkipNode(INT_MAX);
	nInfinity->right = pInfinity;
	pInfinity->left = nInfinity;
	head = nInfinity;
	tail = pInfinity;
	size = 0;
	height = 0;
	srand(time(NULL));
}


SkipList::~SkipList()
{
	clear();
}

void SkipList::insert(int element)
{
	int currentLevel = 0;
	SkipNode *current = iterate(element);
	if (current->data == element) return;
	SkipNode* newSkipNode = new SkipNode(element);
	newSkipNode->left = current;
	newSkipNode->right = current->right;
	current->right->left = newSkipNode;
	current->right = newSkipNode;

	while ((rand() % 10) < 5) {
		if (currentLevel >= height) {
			SkipNode* nInfinity = new SkipNode(INT_MIN), *pInfinity = new SkipNode(INT_MAX);
			nInfinity->right = pInfinity;
			pInfinity->left = nInfinity;
			nInfinity->down = head;
			head->up = nInfinity;
			pInfinity->down = tail;
			tail->up = pInfinity;
			head = nInfinity;
			tail = pInfinity;
			height++;
		}
		while (current->up == NULL)
			current = current->left;

		current = current->up;
		SkipNode* upperSkipNode = new SkipNode(element);
		upperSkipNode->left = current;
		upperSkipNode->right = current->right;
		if (current->right != NULL) current->right->left = upperSkipNode;
		current->right = upperSkipNode;
		upperSkipNode->down = newSkipNode;
		newSkipNode->up = upperSkipNode;

		newSkipNode = upperSkipNode;
		currentLevel++;
	}
	size++;
}

bool SkipList::search(int element)
{
	return iterate(element)->data == element;
}

bool SkipList::erase(int element)
{
	SkipNode* current = iterate(element);
	if (current->data != element) return false;

	while (current != NULL) {
		current->left->right = current->right;
		current->right->left = current->left;
		SkipNode* temp = current->up;
		delete current;
		current = temp;
	}
	size--;
	return true;
}

void SkipList::clear()
{
	SkipNode* current = head, *temp1, *temp2;
	while (current->down != NULL)
		current = current->down;
	while (current != NULL) {
		temp1 = current;
		current = current->right;
		while (temp1 != NULL) {
			temp2 = temp1->up;
			delete temp1;
			temp1 = temp2;
		}
	}
	size = 0;
	height = 0;
}

int SkipList::getSize()
{
	return size;
}

void SkipList::print()
{
	SkipNode* current = head, *start = head;
	while (true) {
		while (current != NULL) {
			if (current->data != INT_MAX && current->data != INT_MIN)
				cout << current->data << ", ";
			current = current->right;
		}
		cout << endl;
		if (start->down != NULL) {
			start = start->down;
			current = start;
		}	
		else
			break;
	}
}
