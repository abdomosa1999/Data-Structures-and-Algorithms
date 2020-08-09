#include "SkipList.h"



SkipList::Node * SkipList::iterate(int element)
{
	Node* current = head;
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
	Node* nInfinity = new Node(INT_MIN), *pInfinity = new Node(INT_MAX);
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
	Node *current = iterate(element);
	if (current->data == element) return;
	Node* newNode = new Node(element);
	newNode->left = current;
	newNode->right = current->right;
	current->right->left = newNode;
	current->right = newNode;

	while ((rand() % 10) < 5) {
		if (currentLevel >= height) {
			Node* nInfinity = new Node(INT_MIN), *pInfinity = new Node(INT_MAX);
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
		Node* upperNode = new Node(element);
		upperNode->left = current;
		upperNode->right = current->right;
		if (current->right != NULL) current->right->left = upperNode;
		current->right = upperNode;
		upperNode->down = newNode;
		newNode->up = upperNode;

		newNode = upperNode;
		currentLevel++;
	}
	size++;
}

bool SkipList::search(int element)
{
	return iterate(element)->data == element;
}

bool SkipList::remove(int element)
{
	Node* current = iterate(element);
	if (current->data != element) return false;

	while (current != NULL) {
		current->left->right = current->right;
		current->right->left = current->left;
		Node* temp = current->up;
		delete current;
		current = temp;
	}
	size--;
	return true;
}

void SkipList::clear()
{
	Node* current = head, *temp1, *temp2;
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
	Node* current = head, *start = head;
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
