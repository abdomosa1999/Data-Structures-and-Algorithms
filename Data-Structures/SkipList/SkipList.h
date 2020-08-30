#pragma once
#include <iostream>
#include <ctime>
using namespace std;

class SkipList;

// a class for the SkipNode data type
class SkipNode {
	int data;
	SkipNode *right, *left, *up, *down;

	friend SkipList;

public:
	// a constructor to initialize fields
	SkipNode(int element);
};

class SkipList
{
	SkipNode * head, * tail;
	int height, size;

	SkipNode * iterate(int element);
public:
	SkipList();
	~SkipList();

	void insert(int element);
	bool search(int element);
	bool erase(int element);
	void clear();
	int getSize();
	void print();
};