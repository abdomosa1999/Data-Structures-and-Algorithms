#include <iostream>
#include <string>
using namespace std;

// A Node struct for the nodes in the linked lists
struct Node {
	string data;
	Node *next;
	Node(string element) {
		data = element;
		next = NULL;
	}
};

class HashTable {
	// data members: n = number of elements, m = number of slots (size of table)
	// and a table which is an array of singly linekd lists (NODE*) 
	int n, m;
	Node** table;

public:
	// the default constructor with 16 slots as a start
	HashTable() {
		n = 0;
		m = 16;
		// create the table and initialize every index to NULL(0)
		table = new Node*[m] {0};
	}

	// a constructor that takes a size of elements in advance
	HashTable(int size) {
		n = 0;
		m = size;
		table = new Node*[m] {0};
	}

	// a destructor that deletes every node and the table itself to free memory
	~HashTable() {
		// iterate over every slot 
		for (int i = 0; i < m; i++) {
			// iterate over all the nodes
			Node* it = table[i];
			while (it != NULL) {
				Node* temp = it->next;
				delete it;
				it = temp;
			}
		}
		// delete the array (table) itself
		delete[] table;
	}

	void insert(string element) {
		// in case that n > m, grow the table to double
		if (n >= m)
			resize(m * 2);

		// create the node
		Node* new_node = new Node(element);
		
		// get the hash value
		int prehashed = prehash(element);
		int index = hash(prehashed);

		// insert the node in its place
		new_node->next = table[index];
		table[index] = new_node;

		n++;
	}

	bool search(string element) {
		// get the hash value
		int prehashed = prehash(element);
		int index = hash(prehashed);

		// iterate over the linked list
		Node* it = table[index];
		while (it != NULL) {
			// if found
			if (it->data == element)
				return true;
			it = it->next;
		}
		return false;
	}

	void remove(string element) {
		// in case that n < m / 4, shrink the table to half
		if (n <= m / 4)
			resize(m / 2);

		// get the hash value
		int prehashed = prehash(element);
		int index = hash(prehashed);

		Node* it = table[index];

		// if the linked list is empty
		if (it == NULL) {
			return;
		}

		// if the value at the beginning
		if (it->data == element) {
				table[index] = it->next;
				delete it;
				n--;
				return;
		}

		// otherwise iterate over the linked list
		while (it->next != NULL) {
			// if the next one is what we are looking for
			if (it->next->data == element) {
				Node* temp = it->next;
				it->next = temp->next;
				delete temp;
				n--;
				return;
			}
			it = it->next;
		}
	}

	void print() {
		// iterate over all slots (linked lists)
		for (int i = 0; i < m; i++) {
			// iterate over all nodes
			Node* it = table[i];
			while (it != NULL) {
				cout << it->data << ", ";
				it = it->next;
			}
			cout << endl;
		}
	}

private:
	// convert the string into a positive integer
	int prehash(string str) {
		int sum = 0;
		for (auto c : str)
			sum += c;
		return sum;
	}

	// map the positive integer within m
	int hash(int prehashed) {
		return prehashed % m;
	}

	// resize the table
	void resize(int new_m) {
		int old_m = m;
		m = new_m;

		// create new table with the desired size
		Node** new_table = new Node*[m] {0};

		// copy all elements into the new table by rehashing and change pointers
		for (int i = 0; i < old_m; i++) {
			Node* it = table[i];
			while (it != NULL) {
				// rehash
				int prehashed = prehash(it->data);
				int index = hash(prehashed);

				Node* temp = it->next;

				// insert the node by changing the pointers to the new table
				it->next = new_table[index];
				new_table[index] = it;

				it = temp;
			}
		}
		// delete the old table
		delete[] table;
		table = new_table;
	}
};
