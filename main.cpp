#include <iostream>
#include "Data-Structures/DynamicArray/DynamicArray.h"
#include "Data-Structures/DynamicArray/DynamicArray.cpp"
#include "Data-Structures/LinkedList/LinkedList.h"
#include "Data-Structures/LinkedList/LinkedList.cpp"
#include "Data-Structures/SkipList/SkipList.h"
#include "Data-Structures/Stack/Stack.h"
#include "Data-Structures/Stack/Stack.cpp"
using namespace std;

void DynamicArrayTest();
void LinkedListTest();
void SkipListTest();
void StackTest();

int main() {
	StackTest();
}

void DynamicArrayTest() {
	DynamicArray<int> list;
	list.pushBack(1);
	list.pushBack(2);
	list.pushBack(4);
	list.insert(5, 3);
	list.insert(3, 2);
	cout << list << endl;
	list[0] = 10;
	list.erase(1);
	list.popBack();
	list.shrink();
	cout << list << endl;
}

void LinkedListTest() {
	LinkedList<int> list;
	list.pushBack(1);
	list.pushBack(2);
	list.pushBack(4);
	list.insert(5, 3);
	list.insert(3, 2);
	cout << list << endl;
	list.erase(2);
	list.popBack();
	cout << list << endl;
}

void SkipListTest() {
	SkipList list;
	list.insert(1);
	list.insert(2);
	list.insert(4);
	list.insert(5);
	list.insert(3);
	list.print();
	list.erase(2);
	list.erase(5);
	list.print();
}

void StackTest() {
	Stack<int> stack;
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);
	stack.push(5);
	stack.print();
	stack.pop();
	stack.pop();
	stack.print();
}
