#include <string>
#include <iostream>
#include <stack>
#include <fstream>
#include "LinkedList.h"
using namespace std;

int main1() {
	LinkedList<string>* list = new LinkedList<string>();
	string s = "Abdel Ghany";
	list->addFirst("Kawther");
	list->addLast("Manar");
	list->addLast("Mahrous");
	list->addLast("Norhan");
	list->addLast("Sama");
	list->addLast("Mostafa");
	list->addLast("Youssef");
	list->addLast("Menna");
	list->addLast("Rowida");
	list->addLast("Yomna");
	list->addLast("Faima Eid");
	list->addLast("Zahraa");
	list->addFirst("Mosa");
	list->insert(2, "Mark");
	list->insert(1, "Mahmoud");
	list->insert(3, s);
	list->print();
	cout << "Index of Abdel Ghany: " << list->indexOf(s) << endl;
	list->remove(s);
	list->reverse();
	list->update(1, "Fatma Eid");
	list->print();
	cout << "Size: " << list->getSize() << ", First: " << list->first()
		<< ", Last: " << list->last() << ", Index 5: " << list->at(5)
		<< "\nIs Abdel Ghany still there? " << list->contains(s) << endl;
	list->clear();
	cout << "Is it empty? " << list->isEmpty() << endl;
	return 0;
}

string checkParanthesis(string str) {
	stack <pair<int, char>> s;
	for (int i = 0; i < str.length(); i++) {
		switch (str[i])
		{
		case '{':
		case '(':
		case '[':
			s.push(make_pair(i, str[i]));
			break;
		case '}':
			if (s.top().second != '{') return to_string(i + 1);
			s.pop();
			break;
		case ')':
			if (s.top().second != '(') return to_string(i + 1);
			s.pop();
			break;
		case ']':
			if (s.top().second != '[') return to_string(i + 1);
			s.pop();
			break;
		}
	}
	if (!s.empty()) {
		s.emplace();
		return to_string(s.top().second + 1);
	}
	return "No Mistakes";
}