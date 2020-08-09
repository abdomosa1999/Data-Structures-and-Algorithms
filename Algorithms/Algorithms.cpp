#include <iostream>
using namespace std;

void BubbleSort(int arr[], int n) 
{
	bool noSwaps;
	for (int i = 0; i < n; i++)
	{
		noSwaps = true;
		for (int j = 1; j < n - i; j++)
		{
			if (arr[j] < arr[j - 1])
			{
				std::swap(arr[j], arr[j - 1]);
				noSwaps = false;
			}
		}
		if (noSwaps) break;
	}
}

void QuickSort(int arr[], int start, int end) {
	if (start < end)
	{
		int pivot = end;
		int left = start;
		int right = end - 1;

		while (true)
		{
			while (arr[left] < arr[pivot]) left++;
			while (right > 0 && arr[right] > arr[pivot]) right--;
			if (left >= right) break;
			else std::swap(arr[left], arr[right]);
		}
		std::swap(arr[left], arr[pivot]);

		QuickSort(arr, start, left - 1);
		QuickSort(arr, left + 1, end);
	}
}

template <typename T>
class BST {
	struct Node {
		T data;
		Node *left, *right;
		Node(T element) {
			data = element;
			left = NULL;
			right = NULL;
		}
	};

	Node *root;

public:
	Node* search(T element)
	{
		Node* it = root;
		while (it != NULL)
		{
			if (it->data == element)
				return it;
			else if (element < it->data)
				it = it->left;
			else
				it = it->right;
		}
		return NULL;
	}

	void insert(T element) 
	{
		Node* it = root;
		while (it != NULL)
		{
			if (it->data == element)
				return;
			else if (element < it->data) {
				if (it->left == NULL) {
					it->left = new Node(element);
					return;
				}
				else
					it = it->left;
			}
			else
			{
				if (it->right == NULL) {
					it->right = new Node(element);
					return;
				}
				else
					it = it->right;
			}
		}
		root = new Node(element);
	}
};
