#include <string>

/* This is a generic class implementing the dynamic array
	data structure in c++ made by: Abdo Mosa*/
template <typename T>
class Array 
{
	T* arr;
	int mLength;
	int mCapacity;

public:
	Array() 
	{
		mLength = 0;
		mCapacity = 16; // default size 16 element
		arr = new T[mCapacity];
	}

	Array(int capacity)
	{
		mLength = 0;
		mCapacity = capacity;
		arr = new T[mCapacity];
	}

	~Array()
	{
		delete[] arr;
	}

	int length()
	{
		return mLength;
	}

	int capacity()
	{
		return mCapacity;
	}

	bool isEmpty() 
	{
		return (mLength == 0);
	}

	T front() 
	{
		checkEmtiness(); // a helper function to reduce code 
		return arr[0];
	}

	T back()
	{
		checkEmtiness();
		return arr[mLength - 1];
	}

	T getValue(int index)
	{
		checkEmtiness();
		checkIndex(index); // a helper function to reduce code
		return arr[index];
	}

	T pop_back()
	{
		checkEmtiness();
		return arr[mLength--];
	}

	void push_back(T element)
	{
		checkCapacity();
		arr[mLength++] = element;
	}

	void insert(int index, T element)
	{
		checkIndex(index);
		checkCapacity();
		// loop throw the array from end to the specific index
		// shifting all elements to make room for the new element
		for (int i = mLength++; i > index; i--)
			arr[i] = arr[i - 1];
		arr[index] = element;
	}

	void update(int index, T element)
	{
		checkIndex(index);
		arr[index] = element;
	}

	/* this method decreses the size to free up the unused space */ 
	void shrink() 
	{
		// do the job with the use of resize() method
		resize(mLength);
	}


	void resize(int size)
	{
		// if it's already the same size we're done
		if (mCapacity == size) return;

		mCapacity = size;
		T* arr = new T[mCapacity];
		for (int i = 0; i < mLength && i < mCapacity; i++)
			arr[i] = this->arr[i];
		delete[] this->arr;
		this->arr = arr;
	}

	bool equals(Array arr)
	{
		if (mLength != arr.mLength) return false;
		for (int i = 0; i < mLength; i++)
			if (this->arr[i] != arr.arr[i]) 
				return false;
		return true;
	}

	Array copy(int fromIndex = 0, int toIndex = mLength - 1)
	{
		checkIndex(fromIndex);
		checkIndex(toIndex);
		if (fromIndex > toIndex) 
			throw "Invalid Arguements";

		Array newArray = new Array(toIndex - fromIndex + 1);
		for (int i = 0; fromIndex <= toIndex; i++, fromIndex++)
			newArray.arr[i] = arr[fromIndex];
		return newArray;
	}

	void reverse()
	{
		// reverse the array by swaping all elements 
		// at the right by the corresponing at the left
		for (int i = 0, j = mLength - 1; i < mLength / 2; i++, j--)
			swap(i, j);
	}

	bool contains(T element)
	{
		return (linearSearch(element) != -1);
	}

	int linearSearch(T element)
	{
		for (int i = 0; i < mLength; i++)
			if (arr[i] == element)
				return i;
		return -1;
	}

	int binarySearch(T element)
	{
		mergeSort();
		return _binarySearch(0, mLength - 1, element); // an alias method to use recursion
	}

	void insertionSort()
	{
		for (int i = 0; i < mLength; i++)
			for (int j = i; j > 0; j--)
				if (arr[j] < arr[j - 1]) 
					swap(j, j - 1);
				else	
					break;
	}

	void mergeSort()
	{
		_mergeSort(0, mLength - 1); // an alias method to use recursion
	}

	int findPeak()
	{
		checkEmtiness();
		if (mLength == 1 || arr[0] >= arr[1]) return 0;
		if (arr[mLength - 1] >= arr[mLength - 2]) return mLength - 1;

		for (int i = 1; i < mLength - 1; i++)
			if (arr[i] >= arr[i - 1] && arr[i] >= arr[i + 1])
				return i;
		return -1;
	}

	std::string toString()
	{
		std::string str = "[";
		for (int i = 0; i < mLength; i++)
		{
			str += std::to_string(arr[i]);
			if (i != mLength - 1)
				str += ", ";
		}
		str += "]";
		return str;
	}

	void erase(int index)
	{
		checkEmtiness();
		checkIndex(index);
		// shift all elements to cover that position
		for (int i = index; i < mLength - 1; i++)
			arr[i] = arr[i + 1];
	}

	void clear()
	{
		delete[] arr;
		mLength = 0;
		mCapacity = 0;
	}

	private:
		/* -------++ helper methods to make code more efficient ++-------*/

		// a function that increases the size of the array if it's full
		void checkCapacity() {
			if (mLength == mCapacity)
				resize(mCapacity * 2 + 1);
		}

		// a function that makes sure that index is valid 
		// and if not, it throws an exception
		void checkIndex(int index) {
			if (index < 0 || index > mLength - 1)
				throw "Index Out of Bounds";
		}

		// a function that makes sure that the array is not empty 
		// and if true, it throws an exception
		void checkEmtiness() {
			if (isEmpty()) 
				throw "Empty Array";
		}

		// a helper function that swaps two elements in the array with their indeces
		void swap(int index1, int index2) {
			int temp = arr[index1];
			arr[index1] = arr[index2];
			arr[index2] = temp;
		}

		// an alias method for the merge sort to use recursion
		void _mergeSort(int start, int end) {

			if (start < end) {
				// split the array in half until it's one element
				int middle = start + (end - start) / 2;
				_mergeSort(start, middle);
				_mergeSort(middle + 1, end);

				// make a temp arrays for both halfs
				int nLeftArr = middle - start + 1;
				int nRightArr = end - middle;
				T* leftArr = new T[nLeftArr];
				T* rightArr = new T[nRightArr];

				// copy the elements to the temp arrays
				for (int i = 0; i < nLeftArr; i++)
					leftArr[i] = arr[start + i];
				for (int i = 0; i < nRightArr; i++)
					rightArr[i] = arr[middle + i + 1];

				// merge the two halfs while sorting them
				int original = start, left = 0, right = 0;
				while (left < nLeftArr && right < nRightArr)
					if (leftArr[left] < rightArr[right])
						arr[original++] = leftArr[left++];
					else
						arr[original++] = rightArr[right++];
				// check if there elements left and add them
				while (left < nLeftArr)
					arr[original++] = leftArr[left++];
				while (right < nRightArr)
					arr[original++] = rightArr[right++];

				// delete the temp arrays
				delete[] leftArr;
				delete[] rightArr;
			}
		}

		// an alias method for the binary search to use recursion
		int _binarySearch(int start, int end, T element) {
			int middle = start + (end - start) / 2;
			if (end >= start) {
				// check the middle if it's there you're done
				if (arr[middle] == element) return middle;
				// if it's bigger, search in the left half only
				else if (arr[middle] > element) _binarySearch(start, middle - 1, element);
				// else it's smaller so search in the right half
				else _binarySearch(middle + 1, end, element);
			}
			else
				return -1;
		}
};