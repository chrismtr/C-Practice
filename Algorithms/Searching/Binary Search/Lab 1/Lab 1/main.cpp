#include <iostream>

int binarySearch(int *array, int left, int right, int key);
void printArray(int *array, int length);

int main()
{
	int *array = new int[10]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	printArray(array, 10);
	
	int index = binarySearch(array, 0, 9, 10);
	if (index > -1)
	{
		std::cout << "Was found at #" << index + 1 << '\n';
	}
	else
	{
		std::cout << "Elements wasn't found\n";
	}

	delete[] array;
	return 0;
}

int binarySearch(int *array, int left, int right, int key)
{
	if (right >= left)
	{
		int mid = left + (right - left) / 2;

		if (array[mid] == key)
			return mid;
		if (array[mid] > key)
			return binarySearch(array, left, mid - 1, key);
		else
			return binarySearch(array, mid + 1, right, key);
	}
	return -1;
}

void printArray(int *array, int length)
{
	for (int count = 0; count < length; ++count)
		std::cout << array[count] << '\t';
	std::cout << '\n';
}