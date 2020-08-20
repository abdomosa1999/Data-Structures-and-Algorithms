#include <iostream>
#include "Data-Structures/DynamicArray/DynamicArray.h"
#include "Data-Structures/DynamicArray/DynamicArray.cpp"
#include "Data-Structures/LinkedList/LinkedList.h"
#include "Data-Structures/LinkedList/LinkedList.cpp"
using namespace std;

void DynamicArrayTest();
void LinkedListTest();

int main() {
	LinkedListTest();
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
	LinkedList<long> list;
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
