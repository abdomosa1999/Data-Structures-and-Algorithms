#include <iostream>
#include "Data-Structures/DynamicArray/DynamicArray.h"
#include "Data-Structures/DynamicArray/DynamicArray.cpp"
using namespace std;


int main() {
	DynamicArray<int> list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(4);
	list.insert(5, 3);
	list.insert(3, 2);
	cout << list << endl;
	list[0] = 10;
	list.erase(1);
	list.pop_back();
	list.shrink();
	cout << list << endl;
}